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

let moveXYB = lift2(Transform.moveXY);
let saveTB = lift1(Transform.saveT);
let stretchB = lift1(Transform.stretch);
let groupAnim = saveTB;
let andThenB = lift2(Transform.andThen);
let (<-+->) = andThenB;

let getTransform =
  fun
  | Behavior(t) => t;

let getTime: behavior(time) = Behavior(t => t);

let timeTrans: (behavior(time), behavior('a)) => behavior('b) =
  (behF, behA) =>
    switch (behF) {
    | Behavior(f) =>
      switch (behA) {
      | Behavior(a) => Behavior((t => a(f(t))))
      }
    };
