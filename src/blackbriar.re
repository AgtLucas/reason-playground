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

/* Mutable Fields */
type human = {
  name: string,
  mutable age: int
};

let myself = { name: "Lucas", age: 26 };
myself.age = myself.age + 1;

/* Variant */
/*
  Yes, No and PrettyMuch aren’t strings, nor references, nor some special data type. They’re called “constructors” (or “tag”). The | bar separates each constructor.
 */
/* Note: variant constructors need to be capitalized. */
type response =
  | Yes
  | No
  | PrettyMuch;

let areYouCrushingIt = Yes;

type account =
  | None
  | Twitter string
  | Facebook string int;

let myAccount = Facebook "AgtLucas" 26;
let friendAccount = Twitter "ReasonML";

let howdy = switch (myAccount) {
  | None => "Hi!"
  | Facebook name age =>
    "Hi " ^ name ^ ", you're " ^ (string_of_int age) ^ "-year-old."
  | Twitter name => "Hello " ^ name ^ "!"
};

/* Linked List */
let myList = [1, 2, 3];
let anotherList = [0, ...myList];
/* Or */
/* type myListType = Empty | NonEmpty int myListType;
let myList = NonEmpty 1 (NonEmpty 2 (NonEmpty 3 Empty)); */

/* Array */
let myArray = [|"Hello", "world", "how are you"|];
let world = myArray.(1);
Array.set myArray 0 "hey";

/* Externals */
external getElementsByClassName : string => array Dom.element =
  "document.getElementsByClassName" [@@bs.val];

/* Destructuring */
let someInts = (10, 20);
let (ten, twenty) = someInts;

type anotherPerson = { name: string, age: int };
let somePerson = { name: "Seneca", age: 30 };
let { name: n, age: a } = somePerson;

/* Recursive function */
let rec neverTerminate = fun () => neverTerminate ();
/* Mutually Recursive Functions */
let rec callSecond = fun () => callFirst () and callFirst = fun () => callSecond ();
/* Currying */
let sum = fun x y => x + y;
let addFour = sum 4;
let six = addFour 2;
/* Or */
/* let sum = fun x => fun y => x + y; */

/* Mutation */
let myMValue = ref 10;
let fakeV = true;
if (fakeV) {
  myMValue := 20;
};

/* Or */
let anotoherMValue = { contents: 10 };
if (fakeV) {
  anotoherMValue.contents = 20;
};

/* Breaking out of loop */
Random.self_init ();
let break = { contents: false };
while (not break.contents) {
  if (Random.int 10 === 3) {
    break.contents = true
  } else {
    print_endline "hello"
  }
};

/* Mutually Recursive Types */
type student = { taughtBy: teacher }
and teacher = { students: list student };

/* Type Arguments */
type intCoordinates = (int, int, int);
let anotherBuddy: intCoordinates = (10, 20, 30);

type coordinates 'a = ('a, 'a, 'a);

type intCoordinatesAlias = coordinates int;
let buddy: intCoordinatesAlias = (10, 20, 20);
/* Or */
let floatBuddy: coordinates float = (10.5, 20.5, 30.5);

/* Composable types and types with arguments */
type result 'a 'b =
  | Ok 'a
  | Error 'b;

type myPayload = { data: string };
type myPayloadResults 'errorType = list (result myPayload 'errorType);

let payloadResults: myPayloadResults string = [
  Ok { data: "Hi!" },
  Ok { data: "Bye!" },
  Error "Something wrong happened!"
];

/* Exceptions */
/* try (somethingThatThrows ()) {
  | Not_found => print_endline "Item not found!"
  | Invalid_argument message => print_endline message
}; */

/* Pattern matching */
type vehicle = { model: string, make: string };
let mclaren = { make: "McLaren", model: "P1" };

type carOwner =
  | CarOwner string vehicle;

let CarOwner name { model: model, make: make } = CarOwner "Lucas" mclaren;
