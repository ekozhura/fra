open Canvas;

let doomfacesImg: Js.t('a) = [%bs.raw "require('./../assets/Doomfaces.png')"];
let earthSrc: Js.t('a) = [%bs.raw "require('./../assets/Canvas_earth.png')"];

let elem = getById("canvas");

let earth = makeImage();
earth|.src(earthSrc);
/* img|.src("https://mdn.mozillademos.org/files/1429/Canvas_earth.png"); */
let doomFaces = makeImage();
doomFaces|.src(doomfacesImg);

type sprite = { sx: float, sy: float, sw: float, sh: float };
let smile: sprite = { sx: 1., sy: 1., sw: 24., sh: 30. };
let norm: sprite = { sx: 210., sy: 3., sw: 50., sh: 62. };
let normLeft: sprite = { sx: 71., sy: 1., sw: 23., sh: 30. };
let normRight: sprite = { sx: 118., sy: 1., sw: 23., sh: 30. };

let drawFace = (ctx: ctx, image: imageElement, sprite: sprite) => {
  ctx|.drawImageSprite(
    image, 
    sprite.sx, sprite.sy, sprite.sw, sprite.sh, 0., 0., sprite.sw, sprite.sh);
};

/* let rec draw = () => {
  let ctx = elem|.getContext;
  ctx|.globalCompositeOperation("destination-over");
  ctx|.imageSmoothingEnabled(false);
  /* ctx|.clearRect(0.,0.,300.,300.);  */
  ctx|.fillStyle("rgba(0, 0, 0, 0.4)");
  ctx|.save;
  /* ctx|.translate(150.,150.); */

  /* let time = makeDate();
  let s = time|.getSeconds;
  let ms = time|.getMilliseconds;
  let angle = ((2.0 *. Js_math._PI) /. 60.0) *. s +. ((2.0 *. Js_math._PI) /. 60000.0) *. ms;
  ctx|.rotate(angle);
  ctx|.translate(105., 0.);
  ctx|.fillRect(0., -12., 50., 24.);
  ctx|.drawImage(img,-12.,-12.); */
  drawFace(ctx, doomFaces, normRight);
  /* ctx|.restore; */
  let id = requestAnimationFrame(draw);
}; */

let t0 = now();
let wiggle = t => 100. *. Js_math.sin(2. *. Js_math._PI *. 2. *. t /. 6000.);
let waggle = t => 100. *. Js_math.cos(2. *. Js_math._PI *. 2. *. t /. 6000.);

let drawDoomFace = (ctx, transformX, transformY) => {
  ctx|.save;
  ctx|.translate(120., 110.);
  ctx|.translate(transformX, transformY);
  ctx|.drawFace(doomFaces, norm);
  ctx|.restore;
  ctx;
};

let rec drawDoomFaceAnimation = () => {
  let ctx = elem|.getContext;
  ctx|.globalCompositeOperation("destination-over");
  ctx|.imageSmoothingEnabled(false);
  ctx|.clearRect(0.,0.,300.,300.);
  ctx|.fillStyle("rgba(0, 0, 0, 0.3)");
  ctx|.fillRect(0.,0.,300.,300.);
  ctx|.save;
  let s = now() -. t0;
  ctx
    |.drawDoomFace(wiggle(s), 0.)
    |.drawDoomFace(0., waggle(s))
    |.restore;

  requestAnimationFrame(drawDoomFaceAnimation);
};

requestAnimationFrame(drawDoomFaceAnimation);