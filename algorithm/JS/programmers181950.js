/*
    const readline = require('readline');
    const rl = readline.createInterface({
        input: process.stdin,
        output: process.stdout
    });

    let input = [];

    rl.on('line', function (line) {
        input = line.split(' ');
    }).on('close', function () {
        str = input[0];
        n = Number(input[1]);
        console.log(str.repeat(n));         //repeat()이라는 함수가 있음.
    });
*/

const readline = require('readline');
const rl = readline.createInterface({
    input: process.stdin,
    output: process.stdout
});

let input = [];

rl.on('line', function (line) {
    input = line.split(' ');
}).on('close', function () {
    for (let i = 0; i < +input[1]; i++) {
         rl.output.write(input[0]);
    }
    /* 개선 코드
        rl.output.write(input[0].repeat(+input[1]));
    */
});
