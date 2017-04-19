var timer;
function getDday() {
    var dday = new Date(document.getElementById('date').value);

    if (dday != "Invalid Date") {
        clearInterval(timer);
        timer = setInterval(function () {
            var diff = new Date(dday - new Date());
            document.getElementById('result').innerText = name(diff);
        }, 1000);
    }
}

function name(diff) {
    var year = diff.getFullYear() - 1970;
    var month = diff.getMonth();
    var date = diff.getDate() - 1;

    var hours = diff.getHours();
    var minutes = diff.getMinutes();
    var secondes = diff.getSeconds();

    if (year < 0) {
        clearInterval(timer);
        return "이미 지나갔습니다.";
    }
    else if (year == 0 && month == 0 && date == 0) {
        clearInterval(timer);
        return "오늘이 디데이입니다."
    }
    else {
        return b(year, "년 ") + b(month, "월 ") + b(date, "일 ")
            + b(hours, "시간 ") + b(minutes, "분 ") + b(secondes, "초 ")
            + "남았습니다.";
    }
}

function b(variable, name) {
    return (variable != 0 ? variable + name : "")
}