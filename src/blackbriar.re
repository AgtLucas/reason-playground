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

let setColor ::color => color; /* Just an example! */
let startAt ::r1 ::r2 => r1 ^ " " ^ r2; /* Just an example! */

/* Optional labeled arguments */
/* let drawCircle ::color ::radius=? () => {
  setColor color;
  switch radius {
    | None => startAt 1 1;
    | Some r_ => startAt r_ r_;
  }
} */

/* Explicitly Passed Optional */
/* let result = switch payloadRadius {
  | None => drawCircle ::color ()
  | Some r => drawCircle ::color radius::r ()
}; */

/* Or */
/* let result = drawCircle ::color radius::?payloadRadius (); */

/* Optional with Default value */
/* let drawCircle ::radius=1 ::color () => {
  setColor color;
  startAt r r;
}; */

/* #TYPES */
let score: int = 10;
/* let myInt = 5;
let myInt = (5 : int); */
let myInt = (5 : int) + (4 : int);
let add (x: int) (y: int) :int => x + y;

/* Types aliases */
type scoreType = int;
let x: scoreType = 10;

/* Tuples */
let myThreeFloast = (20.0, 30.0, 100.0);
let myIntAndString = (20, "Not an Integer");

/* Record */
/* Records must have a type definition */
type person = { age: int, name: string }; /* type */
let me = { age: 26, name: "Lucas" };

/* New records can be created from old one with the ... spread operator */
let meNextYear = { ...me, age: me.age + 1 };

type horsePower = { power: int, metric: bool };

let metric = true;

let horsePower1 = { power: 10, metric };

type car = { name: string, horsePower };

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
