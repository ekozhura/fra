// Generated by BUCKLESCRIPT VERSION 4.0.5, PLEASE EDIT WITH CARE
'use strict';

var Block = require("bs-platform/lib/js/block.js");

function drawPic(el) {
  return /* RenderImage */Block.__(1, [el]);
}

function drawSprite(el, sprite) {
  return /* RenderSprite */Block.__(2, [
            el,
            sprite
          ]);
}

function moveXY(x, y) {
  return /* Translate */Block.__(0, [
            x,
            y
          ]);
}

function andThen(transformA, transformB) {
  return /* ComposedTransform */Block.__(3, [
            transformA,
            transformB
          ]);
}

function saveT(transform) {
  return /* WrappedTransform */Block.__(4, [transform]);
}

function runSingleTransform(ctx, _transform) {
  while(true) {
    var transform = _transform;
    switch (transform.tag | 0) {
      case 0 : 
          ctx.translate(transform[0], transform[1]);
          return /* () */0;
      case 1 : 
          ctx.drawImage(transform[0], 0, 0);
          return /* () */0;
      case 2 : 
          var sprite = transform[1];
          ctx.drawImage(transform[0], sprite[/* sx */0], sprite[/* sy */1], sprite[/* sw */2], sprite[/* sh */3], 0, 0, sprite[/* dw */4], sprite[/* dh */5]);
          return /* () */0;
      case 3 : 
          runSingleTransform(ctx, transform[0]);
          _transform = transform[1];
          continue ;
      case 4 : 
          ctx.save();
          runSingleTransform(ctx, transform[0]);
          ctx.restore();
          return /* () */0;
      
    }
  };
}

function runAllTransforms(ctx, transform) {
  return runSingleTransform(ctx, /* WrappedTransform */Block.__(4, [transform]));
}

exports.drawPic = drawPic;
exports.drawSprite = drawSprite;
exports.moveXY = moveXY;
exports.andThen = andThen;
exports.saveT = saveT;
exports.runSingleTransform = runSingleTransform;
exports.runAllTransforms = runAllTransforms;
/* No side effect */
