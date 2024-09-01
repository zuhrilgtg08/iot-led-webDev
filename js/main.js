const endpointURL = 'http://192.168.253.43';

function getTamuFunction() {
    fetch(endpointURL + '/ruangTamu').then(response => response.text()).then(result => {
        if (result == "ON") {
             btnLedTamu.style.backgroundColor = "#3FA2F6";
             btnLedTamu.textContent = "Turn Off";
             imgTamu.src = "../assets/images/led-red-on.png";
        } else {
             btnLedTamu.style.backgroundColor = "#96C9F4";
             btnLedTamu.textContent = "Turn On";
             imgTamu.src = "../assets/images/led-off.png";
        }
    })
}

function getKerjaFunction() {
    fetch(endpointURL + '/ruangKerja').then(response => response.text()).then(result => {
        if (result == "ON") {
             btnLedKerja.style.backgroundColor = "#3FA2F6";
             btnLedKerja.textContent = "Turn Off";
             imgKerja.src = "../assets/images/led-blue-on.png";
        } else {
             btnLedKerja.style.backgroundColor = "#96C9F4";
             btnLedKerja.textContent = "Turn On";
             imgKerja.src = "../assets/images/led-off.png";
        }
    })
}

function getMakanFunction() { 
    fetch(endpointURL + '/ruangMakan').then(response => response.text()).then(result => {
        if (result == "ON") {
             btnLedMakan.style.backgroundColor = "#3FA2F6";
             btnLedMakan.textContent = "Turn Off";
             imgMakan.src = "../assets/images/led-white-on.png";
        } else {
             btnLedMakan.style.backgroundColor = "#96C9F4";
             btnLedMakan.textContent = "Turn On";
             imgMakan.src = "../assets/images/led-off.png";
        }
    })
}

function getTerasFunction() {
    fetch(endpointURL + '/terasArea').then(response => response.text()).then(result => {
        if (result == "ON") {
             btnLedTeras.style.backgroundColor = "#3FA2F6";
             btnLedTeras.textContent = "Turn Off";
             imgTeras.src = "../assets/images/led-white-on.png";
        } else {
             btnLedTeras.style.backgroundColor = "#96C9F4";
             btnLedTeras.textContent = "Turn On";
             imgTeras.src = "../assets/images/led-off.png";
        }
    })
}

// function getTurnAllOffFunction() { 
//     fetch(endpointURL + '/alwaysOff').then(response => response.text()).then(result => {
//         if (result == "OFF") {
//             btnLedTamu.style.backgroundColor = "#96C9F4";
//             btnLedTamu.textContent = "Turn On";
//             imgTamu.src = "../assets/images/led-off.png";

//             btnLedKerja.style.backgroundColor = "#96C9F4";
//             btnLedKerja.textContent = "Turn On";
//             imgKerja.src = "../assets/images/led-off.png";

//             btnLedMakan.style.backgroundColor = "#96C9F4";
//             btnLedMakan.textContent = "Turn On";
//             imgMakan.src = "../assets/images/led-off.png";

//             btnLedTeras.style.backgroundColor = "#96C9F4";
//             btnLedTeras.textContent = "Turn On";
//             imgTeras.src = "../assets/images/led-off.png";
//         } 
//     })
// }

function setTamuFunction() {
    fetch(endpointURL + '/ruangTamu', {
        method: 'POST',
    }).then(response => response.text()).then(() => location.reload());
}

function setKerjaFunction() {
    fetch(endpointURL + '/ruangKerja', {
        method: 'POST',
    }).then(response => response.text()).then(() => location.reload());
}

function setMakanFunction() {
    fetch(endpointURL + '/ruangMakan', {
        method: 'POST',
    }).then(response => response.text()).then(() => location.reload());
}

function setTerasFunction() {
    fetch(endpointURL + '/terasArea', {
        method: 'POST',
    }).then(response => response.text()).then(() => location.reload());
}

// function setTurnAllOff() {
//     fetch(endpointURL + '/alwaysOff', {
//         method: 'POST',
//     }).then(response => response.text()).then(() => location.reload());
// }

document.addEventListener("DOMContentLoaded", function () {
  const navbarToggle = document.getElementById("navbarToggle");
  const navbarMenu = document.getElementById("navbarMenu");

  navbarToggle.addEventListener("click", function () {
    navbarMenu.classList.toggle("active");
  });
});

getTamuFunction();
getKerjaFunction();
getMakanFunction();
getTerasFunction();
// getTurnAllOffFunction();
