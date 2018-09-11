type time = { time: float };
type behavior('a) = Behavior(time => 'a);
type event('a) = Event(list((time, option('a))));

type behfun('a, 'b) = behavior('a) => behavior('b);