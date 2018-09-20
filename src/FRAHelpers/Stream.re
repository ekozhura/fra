/**
 * Stream implementation described here:
 * https://www.reddit.com/r/ocaml/comments/2y7b3p/i_am_new_to_ocaml_is_there_any_way_to_write/
 * 
 * Here is a better explanation 
 * https://www.cs.cornell.edu/courses/cs3110/2017fa/l/12-streams/notes.html
 * 
 */

type stream('a) = Stream('a, unit => stream('a));

let head: stream('a) => 'a = (Stream(x, _)) => x;
let tail: stream('a) => stream('a) = (Stream(_, xs)) => xs();

let rec ap = (step, n) => Stream(n, () => ap(step, n + step));

let rec take = (n, s) => switch(n) {
| 0 => []
| n => [head(s), ...take(n - 1, tail(s))]
};

let rec drop = (n, s) => switch(n) {
| 0 => s
| _ => drop(n - 1, tail(s))
};

let rec mapS = (f, Stream (h, tf)) =>
  Stream (f(h), () => mapS (f, (tf ())));

let rec mapS2 = (f, Stream(h1, tf1), Stream (h2, tf2)) => 
  Stream (f(h1, h2), () => mapS2 (f, tf1(), tf2()));
