
var N = 4;	//just change the value of N and the visuals will reflect the configuration!

var board = (function createArray (N) {
    var result = [];
    for (var i = 0; i < N; i++) {
        result [i] = Array.apply(null, Array(N)).map(Number.prototype.valueOf,0);
    }
    return result;
}) (N);

var queens = (function qSetup (N) {
    var result = [];
    for (var i = 0; i < N; i++) {
        result [i] = [-1,-1];
    }
    return result;
}) (N);


function validState (row, col, currentQueen) {
    for (var q = 0; q < currentQueen; q++) {
        var currentQ = queens [q];
        if ( row === currentQ [0] || col === currentQ [1] || ( Math.abs(currentQ [0] - row) === Math.abs(currentQ [1] - col)) ) {
            return false;
        }
    }
    return true;
}

function nQ (currentQueen, currentCol) {
    if (currentQueen >= N) {
        return true;
    }
    var found = false, row = 0;
    while ( (row < N) && (!found) ) {
            if (validState (row, currentCol, currentQueen)) {
            queens [currentQueen] [0] = row;
            queens [currentQueen] [1] = currentCol;
            found = nQ (currentQueen + 1, currentCol + 1);
        }
        row++;
    }
    
    return found;
}

nQ (0, 0);
var s='(';
for (var i=0;i<N-1;i++) {
    s=s+queens[i][0]+', ';
}
s=s+queens[i][0]+')';
console.log(s);