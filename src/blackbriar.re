/* Functions */
let greet = fun name => "Hello " ^ name;

/* We can omit the keyword `fun` */
let increment x => x + 1;
let double x => x + x;
let eleven = increment (double 5);

/* Function always takes an argument, but you can use () to `no argument` */
let logSomething () => {
  print_endline "Hello Reason!";
}; /* <= don't forget the ; */

/* Labeled arguments */

/* The example bellow can be confusing */
/* let addCoordinates x y => {

}; */

/* We can attach label to an argument */
let addCoordinates x::x y::y => {
  x + y;
};

/* Or */
let addCoordinatesShorthand ::x ::y => {
  x + y;
};

/* Optional labeled arguments */
/* let drawCircle ::color ::radius=? () => {
  setColor color;
  switch radius {
    | None => startAt 1 1;
    | Some r_ => startAt r_ r_;
  }
} */

Random.self_init ();
let break = {contents: false};
while (not break.contents) {
  if (Random.int 10 === 3) {
    break.contents = true
  } else {
    print_endline "hello"
  }
};

type coordinates 'a = ('a, 'a, 'a);

type intCoordinatesAlias = coordinates int;
let buddy: intCoordinatesAlias = (10, 20, 20);
