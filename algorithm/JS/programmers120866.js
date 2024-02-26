function solution(board) {
  let x = -1;
  let y = -1;
  let caution_place = 0;
  let caution = {
    0: [-1, -1],
    1: [-1, 0],
    2: [-1, 1],
    3: [0, -1],
    4: [0, 1],
    5: [1, -1],
    6: [1, 0],
    7: [1, 1],
  };

  while (++y < board.length) {
    x = -1;
    while (++x < board[0].length) {
      if (board[y][x] === 1) {
        caution_place++;

        for (let dir = 0; dir < 8; dir++) {
          let [dir_x, dir_y] = caution[dir];

          if (
            x + dir_x < 0 ||
            y + dir_y < 0 ||
            y + dir_y === board.length ||
            x + dir_x === board[0].length
          )
            continue;

          if (board[y + dir_y][x + dir_x] === 0) {
            board[y + dir_y][x + dir_x] = -1;
            caution_place++;
          }
        }
      }
    }
  }
  return board.length * board[0].length - caution_place;
}

/*
다른사람 풀이
function solution(board) {
  let outside = [
    [-1, 0],
    [-1, -1],
    [-1, 1],
    [0, -1],
    [0, 1],
    [1, 0],
    [1, -1],
    [1, 1],
  ];
  let safezone = 0;

  board.forEach((row, y, self) =>
    row.forEach((it, x) => {
      if (it === 1) return false;
      return outside.some(([oy, ox]) => !!self[oy + y]?.[ox + x])
        ? false
        : safezone++;
    })
  );

  return safezone;
}
*/
