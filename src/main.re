open Transform;
open Behavior;
open ImageData;
open Time;

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

let startAt = (x, y) => moveXYB(const(x), const(y));

let multB = lift2(( *. ));
let speedUp = n => timeTrans(multB(varied(n), getTime));

let stretchFun = varied(stretchT);
let newTransform = const(staticFace(straight)) |> andThenB(moveXYB(varied(wiggle), const(20.)));

/**
 * One thing to consider is that each transform affect the whole scene
 * So for example:
 *      moveXYB(varied(wiggle), const(0.))
 *      >=> stretchB(const(0.5))
 * is not the same as:
 *      stretchB(const(0.5))
 *      >=> moveXYB(varied(wiggle), const(0.))
 */

let allTransforms =
  groupAnim(
    startAt(120., 20.)
    >=> stretchB(const(1.5))
    >=> moveXYB(varied(waggle), const(20.))
    >=> const(staticFace(straight))
    |> speedUp(_ => 2.),
  )
  >=> groupAnim(
        startAt(120., 120.)
        >=> moveXYB(varied(waggle), const(20.))
        >=> stretchB(const(1.5))
        >=> const(staticFace(straight))
        |> speedUp(_ => 2.),
      );
/* >=> groupAnim(
     startAt(20., 20.)
     >=> moveXYB(varied(wiggle), const(0.))
     >=> stretchB(const(0.5))
     >=> groupAnim(moveXYB(varied(wiggle), const(0.)) >=> setToCenterB >=> lookB)
     >=> groupAnim(moveXYB(const(0.), varied(waggle)) >=> setToCenterB >=> lookB),
   ); */

Draw.animate(allTransforms);

/* Draw.drawStatic(newTransform);  */
