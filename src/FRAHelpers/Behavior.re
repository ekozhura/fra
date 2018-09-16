type time = float;

type behavior('a) =
  | Behavior(time => 'a);

let varied = fn => Behavior(fn);
let const = n => Behavior(_ => n);

let lift0 = x => Behavior(_ => x);
let lift1 = (fn, behA) =>
  switch (behA) {
  | Behavior(x) => Behavior((t => fn(x(t))))
  };

let lift2 = (fn, behA, behB) =>
  switch (behA) {
  | Behavior(a) =>
    switch (behB) {
    | Behavior(b) => Behavior((t => fn(a(t), b(t))))
    }
  };

let beh5 = const(5);

let moveXYB = lift2(Transform.moveXY);
let saveTB = lift1(tr => Transform.WrappedTransform(tr));

let andThenB = lift2(Transform.andThen);
let (<-+->) = andThenB;

let getTransform =
  fun
  | Behavior(t) => t;
