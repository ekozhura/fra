open Canvas;

let doomfacesImg: Js.t('a) = [%bs.raw "require('./../assets/Doomfaces.png')"];

let elem = getById("canvas");

let img = makeImage();
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

let wiggle = t => Js_math.sin(t *. Js_math._PI);

let rec drawDoomFace = () => {
  let ctx = elem|.getContext;
  ctx|.globalCompositeOperation("destination-over");
  ctx|.imageSmoothingEnabled(false);
  ctx|.clearRect(0.,0.,300.,300.);
  ctx|.save;
  ctx|.translate(150., 150.);
  let time = makeDate();
  let s = time|.getSeconds;
  let ms = time|.getMilliseconds;
  drawFace(ctx, doomFaces, norm);
  ctx|.restore;
  let id = requestAnimationFrame(drawDoomFace);
};

requestAnimationFrame(drawDoomFace);