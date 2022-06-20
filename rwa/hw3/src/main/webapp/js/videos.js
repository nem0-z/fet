const add = document.getElementById("addnew");

const editHandler = function(event) {
    event.preventDefault();
    const id = this.parentNode.firstElementChild.textContent;
    const contextPath = "http://localhost:8080/hw2_war_exploded/";
    const resource = "video_edit.jsp"
    location.replace(`${contextPath}${resource}?id=${id}`);
};

const deleteHandler = function(event) {
    const id = this.parentNode.firstElementChild.textContent;
    const api = "http://localhost:8080/hw2_war_exploded/api";
    const endpoint = "video_delete";
    const url = `${api}/${endpoint}?` + new URLSearchParams({
        id: id,
    });

    fetch(url)
        .then(res => res.status === 200 && location.reload())
        .catch(e => console.error(e));
};

const addHandler = function(event) {
    event.preventDefault();
    const id = this.parentNode.firstElementChild.textContent;
    const contextPath = "http://localhost:8080/hw2_war_exploded/";
    const resource = "video_edit.jsp"
    location.replace(`${contextPath}${resource}`);
}


for (const node of document.querySelectorAll('#manage-video-edit-btn')) {
    node.onclick = editHandler;
}

for (const node of document.querySelectorAll('#manage-video-delete-btn')) {
    node.onclick = deleteHandler;
}

add.onclick = addHandler;
