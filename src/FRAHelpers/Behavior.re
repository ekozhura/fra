type time = float;

type behavior('a) =
  | Behavior(time => 'a);

let lift0 = x => Behavior(_ => x);

let lift1 = (fn, Behavior(a)) => Behavior(t => fn(a(t)));

let lift2 = (fn, Behavior(a), Behavior(b)) => Behavior(t => fn(a(t), b(t)));

let lift3 = (fn, Behavior(a), Behavior(b), Behavior(c)) => Behavior(t => fn(a(t), b(t), c(t)));

let varied = fn => Behavior(fn);
let const = lift0;

let moveXYB = lift2(Transform.moveXY);
let saveTB = lift1(Transform.wrapT);
let stretchB = lift1(Transform.stretch);
let groupAnim = saveTB;
let andThenB = lift2(Transform.andThen);
let (>=>) = andThenB;

let getTransform = (Behavior(t)) => t;

let getTime: behavior(time) = Behavior(t => t);

let timeTrans: (behavior(time), behavior('a)) => behavior('b) =
  (Behavior(currentTime), Behavior(a)) => Behavior(t => a(currentTime(t)));
