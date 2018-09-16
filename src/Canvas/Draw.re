open Canvas;

let renderSprite = (ctx: ctx, image: imageElement, sprite: sprite) =>
  ctx->(drawImageSprite(image, sprite.sx, sprite.sy, sprite.sw, sprite.sh, 0., 0., sprite.sw, sprite.sh));

let elem = getById("canvas");

let rec drawEngine = (allTransforms, t) => {
  let ctx = elem->getContext;
  ctx->globalCompositeOperation("multiply");
  ctx->imageSmoothingEnabled(false);
  ctx->clearRect(0., 0., 300., 300.);
  ctx->save;
  Transform.runAllTransforms(ctx, allTransforms(t));
  requestAnimationFrame(drawEngine(allTransforms));
};
