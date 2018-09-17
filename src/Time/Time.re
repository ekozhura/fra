/**
 * Timing functions
 */

let wiggle = t => 60. *. Js_math.sin(2. *. Js_math._PI *. 2. *. t /. 6000.);
let waggle = t => 60. *. Js_math.cos(2. *. Js_math._PI *. 2. *. t /. 6000.);
let stretchT = t => 0.5 +. 0.5 *. Js_math.sin(Js_math._PI *. t /. 6000.);