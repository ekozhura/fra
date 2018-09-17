open Canvas;

type transform =
  | Translate(float, float)
  | RenderImage(imageElement)
  | RenderSprite(imageElement, sprite)
  | ComposedTransform(transform, transform)
  | Stretch(float)
  | WrappedTransform(transform);

let drawPic: imageElement => transform = el => RenderImage(el);
let drawSprite: (imageElement, sprite) => transform = (el, sprite) => RenderSprite(el, sprite);
let moveXY: (float, float) => transform = (x, y) => Translate(x, y);
let stretch: float => transform = x => Stretch(x);
let andThen: (transform, transform) => transform = (transformA, transformB) => ComposedTransform(transformA, transformB);
let wrapT: transform => transform = transform => WrappedTransform(transform);

let rec runSingleTransform = (ctx, transform) => {
  switch (transform) {
    | Translate(x, y) => ctx->translate(x, y)
    | RenderImage(el) => ctx->drawImage(el, 0., 0.)
    | RenderSprite(image, sprite) =>
      ctx->drawImageSprite(image, sprite.sx, sprite.sy, sprite.sw, sprite.sh, 0., 0., sprite.dw, sprite.dh)
    | Stretch(f) => ctx->scale(f, f)
    | ComposedTransform(transformA, transformB) =>
      runSingleTransform(ctx, transformA);
      runSingleTransform(ctx, transformB);
    | WrappedTransform(transform) =>
      ctx->save;
      runSingleTransform(ctx, transform);
      ctx->restore;
  };
};

let runAllTransforms = (ctx, transform) => runSingleTransform(ctx, wrapT(transform));
