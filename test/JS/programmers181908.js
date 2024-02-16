function solution(my_string, is_suffix) {
  let t = my_string.slice(is_suffix.length).matchAll(is_suffix);
  for (
    let idx = my_string.length - is_suffix.length, s_idx = 0;
    idx < my_string.length;
    idx++, s_idx++
  ) {
    console.log(my_string[idx], is_suffix[s_idx]);
    if (my_string[idx] !== is_suffix[s_idx]) return 0;
  }
  return 1;
}

/* user solution
    const solution = (str, suff) => str.endsWith(suff) ? 1 : 0
*/
/* user solution2
    function solution(my_string, is_suffix) {
        return my_string.slice(my_string.length - is_suffix.length) === is_suffix ? 1 : 0
    }
*/
