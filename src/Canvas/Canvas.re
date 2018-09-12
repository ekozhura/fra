/* https://github.com/reasonml-community/reason-maze/blob/master/src/FFI/Canvas.re */

type canvasElement;
type canvasRenderingContext2D;
type ctx = canvasRenderingContext2D;
type animationFrameID;
type imageElement;
type date;

let getById: string => canvasElement = [%bs.raw
  {|function(arg) {
  return document.getElementById(arg)
 }|}
];

[@bs.set] external globalCompositeOperation: (ctx, string) => unit = "";
[@bs.set] external imageSmoothingEnabled: (ctx, bool) => unit = "";

[@bs.send] external getContext: (canvasElement, [@bs.as "2d"] _) => canvasRenderingContext2D = "getContext";
[@bs.send] external save: ctx => unit = "";
[@bs.send] external restore: ctx => unit = "";
[@bs.send] external clearRect: (ctx, float, float, float, float) => unit = "";
[@bs.send] external fillRect: (ctx, float, float, float, float) => unit = "";
[@bs.send] external translate: (ctx, float, float) => unit = "";
[@bs.send] external setTransform: (ctx,  float, float, float, float, float, float) => unit = "";
[@bs.send] external rotate: (ctx, float) => unit = "";
[@bs.set] external fillStyle: (ctx, string) => unit = "";
[@bs.send] external drawImage: (ctx, imageElement, float, float) => unit = "";
[@bs.send] external drawImageSprite: (ctx, imageElement, float, float, float, float, float, float, float, float) => unit = "drawImage";

[@bs.new] external makeImage: unit => imageElement = "Image";
[@bs.set] external src: (imageElement, Js.t('a)) => unit = "";

[@bs.new] external makeDate: unit => date = "Date";
[@bs.val] external now: unit => float = "window.Date.now";
[@bs.send] external getSeconds: date => float = "";
[@bs.send] external getMilliseconds: date => float = "";

[@bs.val] external requestAnimationFrame: (unit => animationFrameID) => animationFrameID = "window.requestAnimationFrame";