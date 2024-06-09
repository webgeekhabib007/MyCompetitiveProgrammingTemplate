const readline = require('readline')

const rl = readline.createInterface({
    //input : require('fs').createReadStream("input.txt"),
    input: process.stdin,
    output: process.stdout,
    error : process.stderr,
})
const lines = []
rl.on('line', (input) => {
    lines.push(input);
})
rl.on('close', () => {
    testcase = parseInt(lines[0]);
    inputIdx  = 1;
    for(let cases=0;cases<testcase;cases++){
        var [n,f,k,..._] = lines[inputIdx++].split(" ").map(Number);
        var arr = lines[inputIdx++].split(" ").map(Number);
        solve(n,f,k,arr);
    }
})


function get(r){
    let cnt=0;
    for(let i=0;i<r;i++){
        let y = 0;
        let left =0,right=r-1;
        while(left <= right){
            let mid = Math.floor((left + right)/2);
            if(i*i + mid*mid < r*r){
                y = mid;
                left = mid+1;
            }else right = mid -1;
        }
        cnt+= (y+1);
    }
    cnt = 2*cnt - r;
    cnt = 2*cnt - (2*r-1);
    return cnt;
}


function solve(n,f,k,arr) {
    var tar = arr[f-1];
    k--;
    arr.sort((a,b)=>b-a);
    let pos = 0;
    while(arr[pos]!=tar)pos++;
    let left = pos;
    pos = n-1;
    while(arr[pos]!=tar)pos--;
    let right = pos;
    if(right - left+1 ==1){
        console.log(k>=left ? "YES" : "NO");
    }else{
        if(k<left)console.log("NO");
        else if(k>=left && k<right){
            console.log("MAYBE");
        }else console.log("YES");
    }

}
