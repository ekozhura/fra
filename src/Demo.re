open Canvas;
open Transform;
open Behavior;

let doomfacesImg: Js.t('a) = [%bs.raw "require('./../assets/Doomfaces.png')"];

let doomFaces = makeImage();
doomFaces->(src(doomfacesImg));

let straight: sprite = {sx: 212., sy: 1., sw: 49., sh: 62., dw: 49., dh: 62.};
let right: sprite = {sx: 160., sy: 1., sw: 49., sh: 62., dw: 49., dh: 62.};
let left: sprite = {sx: 264., sy: 1., sw: 49., sh: 62., dw: 49., dh: 62.};

let t0 = now();
let wiggle = t => 60. *. Js_math.sin(2. *. Js_math._PI *. 2. *. t /. 6000.);
let waggle = t => 60. *. Js_math.cos(2. *. Js_math._PI *. 2. *. t /. 6000.);

let goThroughSprites = (arr, t, n) => {
  let index = t mod n;
  arr[index];
};

let setToCenter = moveXY(100., 100.);
let look = (speed, n, t) =>
  goThroughSprites([|left, straight, right, straight|], Js_math.floor_int(t /. 6000. *. speed) mod n, n);

let lookB = varied(t => drawSprite(doomFaces, look(10., 4, t)));
let setToCenterB = moveXYB(const(100.), const(100.));

let staticFace = drawSprite(doomFaces);
let makeSmaller: (float, Canvas.sprite) => Canvas.sprite =
  (f, o) => {sx: o.sx, sy: o.sy, sw: o.sw, sh: o.sh, dw: o.dw /. f, dh: o.dh /. f};

let startAt = (x, y) => moveXYB(const(x), const(y));
let (<->) = andThenB;
let multB = lift2(( *. ));
let speedUp = n => timeTrans(multB(varied(n), getTime));

let stretchFun = varied(t => 0.5 +. 0.5 *. Js_math.sin(Js_math._PI *. t /. 6000.));
let allTransforms =
  /*groupAnim(*/
  /*startAt(120., 20.)*/
  /*<-> moveXYB(varied(waggle), const(20.))*/
  /*<-> const(staticFace(straight))*/
  /*|> speedUp(_ => 2.),*/
  /*)*/
  /*<-> */
  groupAnim(
    startAt(20., 20.)
    <-> stretchB(stretchFun)
    <-> moveXYB(varied(wiggle), const(0.))
    <-> groupAnim(moveXYB(varied(wiggle), const(0.)) <-> setToCenterB <-> lookB)
    <-> groupAnim(moveXYB(const(0.), varied(waggle)) <-> setToCenterB <-> lookB),
  );

let animate = () => {
  requestAnimationFrame(Draw.drawEngineB(allTransforms)) |> ignore;
  ();
};

animate();
