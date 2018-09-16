open Canvas;
open Transform;
open Behavior;

let doomfacesImg: Js.t('a) = [%bs.raw "require('./../assets/Doomfaces.png')"];

let doomFaces = makeImage();
doomFaces->(src(doomfacesImg));

let straight: sprite = {sx: 212., sy: 1., sw: 49., sh: 62.};
let right: sprite = {sx: 160., sy: 1., sw: 49., sh: 62.};
let left: sprite = {sx: 264., sy: 1., sw: 49., sh: 62.};

let t0 = now();
let wiggle = t => 60. *. Js_math.sin(2. *. Js_math._PI *. 2. *. t /. 6000.);
let waggle = t => 60. *. Js_math.cos(2. *. Js_math._PI *. 2. *. t /. 6000.);

let goThroughSprites: (int, int) => transform =
  (t, n) => {
    let index = t mod n;
    let image = [|left, straight, right, straight|][index];
    drawSprite(doomFaces, image);
  };

let setToCenter = moveXY(100., 100.);
let look = (speed, n, t) => goThroughSprites(Js_math.floor_int(t /. 6000. *. speed) mod n, n);

let firstFace = t => moveXY(wiggle(t), 0.) <-> setToCenter <-> look(10., 4, t);
let secondFace = t => moveXY(0., waggle(t)) <-> setToCenter <-> look(15., 4, t);

let lookB = varied(look(10., 4));
let setToCenterB = moveXYB(const(100.), const(100.));

let allTransforms =
  moveXYB(const(20.), const(20.))
  <-+-> moveXYB(varied(wiggle), const(0.))
  <-+-> saveTB(moveXYB(varied(wiggle), const(0.)) <-+-> setToCenterB <-+-> lookB)
  <-+-> saveTB(moveXYB(const(0.), varied(waggle)) <-+-> setToCenterB <-+-> lookB);

let animate = () => {
  requestAnimationFrame(Draw.drawEngineB(allTransforms)) |> ignore;
  ();
};

animate();
