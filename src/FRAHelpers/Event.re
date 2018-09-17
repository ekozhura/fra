open Behavior;

type user_action = Click;

type occ('a) = list((time, option('a)));
type event('a) = Event(time => occ('a));

let runEvent = (event, u) => switch(event) {
| Event(fe) => fe(u);
}