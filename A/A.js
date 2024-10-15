.pragma library

.import B as B

function test() {
    console.log("Calling B from A")
    B.B.test()
}