open Canvas;

type transform =
  | Translate(float, float)
  | RenderImage(Canvas.imageElement)
  | RenderSprite(imageElement, sprite)
  | ComposedTransform(transform, transform)
  | WrappedTransform(transform);

let drawPic: imageElement => transform = el => RenderImage(el);
let drawSprite: (imageElement, sprite) => transform = (el, sprite) => RenderSprite(el, sprite);
let moveXY: (float, float) => transform = (x, y) => Translate(x, y);
let andThen: (transform, transform) => transform =
  (transformA, transformB) => ComposedTransform(transformA, transformB);
let saveT: transform => transform = transform => WrappedTransform(transform);

let (<->) = andThen;

let rec runSingleTransform: (ctx, transform) => unit =
  (ctx, transform) =>
    switch (transform) {
    | Translate(x, y) => ctx->translate(x, y)
    | RenderImage(el) => ctx->drawImage(el, 0., 0.)
    | RenderSprite(image, sprite) =>
      ctx->drawImageSprite(image, sprite.sx, sprite.sy, sprite.sw, sprite.sh, 0., 0., sprite.sw, sprite.sh)
    | ComposedTransform(transformA, transformB) =>
      runSingleTransform(ctx, transformA);
      runSingleTransform(ctx, transformB);
    | WrappedTransform(transform) =>
      ctx->save;
      runSingleTransform(ctx, transform);
      ctx->restore;
    };

let runAllTransforms = (ctx, transform) => runSingleTransform(ctx, WrappedTransform(transform));
