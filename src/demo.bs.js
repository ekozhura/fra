// Generated by BUCKLESCRIPT VERSION 4.0.1, PLEASE EDIT WITH CARE
'use strict';

var Curry = require("bs-platform/lib/js/curry.js");
var Canvas = require("./Canvas/Canvas.bs.js");

var doomfacesImg = (require('./../assets/Doomfaces.png'));

var earthSrc = (require('./../assets/Canvas_earth.png'));

var elem = Curry._1(Canvas.getById, "canvas");

var earth = new Image();

earth.src = earthSrc;

var doomFaces = new Image();

doomFaces.src = doomfacesImg;

var norm = /* record */[
  /* sx */210,
  /* sy */3,
  /* sw */50,
  /* sh */62
];

function drawFace(ctx, image, sprite) {
  ctx.drawImage(image, sprite[/* sx */0], sprite[/* sy */1], sprite[/* sw */2], sprite[/* sh */3], 0, 0, sprite[/* sw */2], sprite[/* sh */3]);
  return /* () */0;
}

var t0 = window.Date.now();

function wiggle(t) {
  return 100 * Math.sin(2 * Math.PI * 2 * t / 6000);
}

function waggle(t) {
  return 100 * Math.cos(2 * Math.PI * 2 * t / 6000);
}

function drawDoomFace(ctx, transformX, transformY) {
  ctx.save();
  ctx.translate(120, 110);
  ctx.translate(transformX, transformY);
  drawFace(ctx, doomFaces, norm);
  ctx.restore();
  return ctx;
}

function drawDoomFaceAnimation() {
  var ctx = elem.getContext("2d");
  ctx.globalCompositeOperation = "destination-over";
  ctx.imageSmoothingEnabled = false;
  ctx.clearRect(0, 0, 300, 300);
  ctx.fillStyle = "rgba(0, 0, 0, 0.3)";
  ctx.fillRect(0, 0, 300, 300);
  ctx.save();
  var s = window.Date.now() - t0;
  drawDoomFace(drawDoomFace(ctx, wiggle(s), 0), 0, waggle(s)).restore();
  return window.requestAnimationFrame(drawDoomFaceAnimation);
}

window.requestAnimationFrame(drawDoomFaceAnimation);

var smile = /* record */[
  /* sx */1,
  /* sy */1,
  /* sw */24,
  /* sh */30
];

var normLeft = /* record */[
  /* sx */71,
  /* sy */1,
  /* sw */23,
  /* sh */30
];

var normRight = /* record */[
  /* sx */118,
  /* sy */1,
  /* sw */23,
  /* sh */30
];

exports.doomfacesImg = doomfacesImg;
exports.earthSrc = earthSrc;
exports.elem = elem;
exports.earth = earth;
exports.doomFaces = doomFaces;
exports.smile = smile;
exports.norm = norm;
exports.normLeft = normLeft;
exports.normRight = normRight;
exports.drawFace = drawFace;
exports.t0 = t0;
exports.wiggle = wiggle;
exports.waggle = waggle;
exports.drawDoomFace = drawDoomFace;
exports.drawDoomFaceAnimation = drawDoomFaceAnimation;
/* doomfacesImg Not a pure module */
