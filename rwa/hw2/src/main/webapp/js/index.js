const voteFirst = document.getElementById("voteFirst");
const voteSecond = document.getElementById("voteSecond");

const handleVote = (ev) => {
    ev.preventDefault();
    const winnerButtonNode = ev.target;
    const winnerButtonNodeId = winnerButtonNode.getAttribute("id");
    const loserButtonNode = winnerButtonNodeId === "voteFirst" ? voteSecond : voteFirst ;

    const winnerVideoId = winnerButtonNode.parentNode.getAttribute("id");
    const loserVideoId = loserButtonNode.parentNode.getAttribute("id");

    const api = "http://localhost:8080/hw2_war_exploded/api";
    const endpoint = "vote"
    const url = `${api}/${endpoint}?` + new URLSearchParams({
        winner: winnerVideoId,
        loser: loserVideoId,
    });

    fetch(url)
        .then(res => res.status === 200 && location.reload())
        .catch(e => console.error(e));
}

voteFirst.onclick = handleVote;
voteSecond.onclick = handleVote;
