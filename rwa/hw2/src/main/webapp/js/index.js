const voteFirst = document.getElementById("voteFirst");
const voteSecond = document.getElementById("voteSecond");
const shareBtn = document.getElementById("shareBtn");
const videoCompetitors = document.querySelectorAll('.voting iframe');

const share = function(ev) {
    ev.preventDefault();
    const copyText = `Video 1: ${videoCompetitors[0].src}\nVideo 2: ${videoCompetitors[1].src}`;
    if (navigator) {
        navigator.clipboard.writeText(copyText);
        alert("Copied to clipboard!\n" + copyText);
    }
}

const handleVote = function(ev) {
    ev.preventDefault();
    const winnerButtonNode = this;
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
shareBtn.onclick = share;

document.addEventListener("keypress", (ev) => {
    const name = ev.key;
    if (name !== "1" || name !== "2") {
        let ctx = null;
        if (name === "1") {
            ctx = voteFirst;
        } else if (name === "2") {
            ctx = voteSecond;
        }

        handleVote.call(ctx, new Event(""));
    }
});