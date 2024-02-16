function solution(hp) {
  const ant = [5, 3, 1];
  let cnt = 0;
  for (num of ant) {
    cnt += ~~(hp / num);
    hp = hp % num;
  }
  return cnt;
}
