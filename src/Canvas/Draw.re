open Canvas;

let renderSprite = (ctx: ctx, image: imageElement, sprite: sprite) =>
  ctx->(drawImageSprite(image, sprite.sx, sprite.sy, sprite.sw, sprite.sh, 0., 0., sprite.sw, sprite.sh));

let elem = elementToCanvasElement(getById("canvas"));

Canvas.onEvent(getById("canvas"), "click", () => {
  Js.log("click");
});

let drawStatic = allTransforms => {
  let ctx = elem->getContext;
  ctx->globalCompositeOperation("multiply");
  ctx->imageSmoothingEnabled(false);
  ctx->clearRect(0., 0., 300., 300.);
  switch (allTransforms) {
  | Behavior.Behavior(transform) => Transform.runAllTransforms(ctx, transform(0.))
  };
};

let rec drawAnimation = (allTransforms, t) => {
  let ctx = elem->getContext;
  ctx->globalCompositeOperation("multiply");
  ctx->imageSmoothingEnabled(false);
  ctx->clearRect(0., 0., 300., 300.);
  ctx->save;
  Transform.runAllTransforms(ctx, allTransforms(t));
  requestAnimationFrame(drawAnimation(allTransforms));
};

let rec drawAnimationB = (allTransforms, t) => {
  let ctx = elem->getContext;
  ctx->globalCompositeOperation("multiply");
  ctx->imageSmoothingEnabled(false);
  ctx->clearRect(0., 0., 300., 300.);
  ctx->save;
  switch (allTransforms) {
  | Behavior.Behavior(transform) => Transform.runAllTransforms(ctx, transform(t))
  };

  requestAnimationFrame(drawAnimationB(allTransforms));
};

let animate = (allTransforms) => {
  requestAnimationFrame(drawAnimationB(allTransforms)) |> ignore;
  ();
};
