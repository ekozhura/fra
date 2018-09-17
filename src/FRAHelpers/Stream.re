/**
 * Stream implementation described here:
 * https://www.reddit.com/r/ocaml/comments/2y7b3p/i_am_new_to_ocaml_is_there_any_way_to_write/
 */

type stream('a) = Stream('a, unit => stream('a));

let head: stream('a) => 'a = fun | Stream(x, _) => x;
let tail: stream('a) => stream('a) = fun | Stream(_, xs) => xs();

let rec ap = (step, n) => Stream(n, () => ap(step, n + step));

let rec take = (n, s) => switch(n) {
| 0 => []
| n => [head(s), ...take(n - 1, tail(s))]
};