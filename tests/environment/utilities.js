const fs = require('fs');
const { TextDecoder } = require('util');

const wasmFile = process.argv[2];
if (!wasmFile) {
    console.error("[[ ERRROR ]]: Missing .wasm file!");
    process.exit(1);
}

const wasmBuffer = fs.readFileSync(wasmFile);
let wasmMemory;

// ------------------------------------------------------------
//  Funciones reutilizadas del index.html
// ------------------------------------------------------------

function getStringFromMem(offset) {
    if (!wasmMemory) return "";
    const buffer = new Uint8Array(wasmMemory.buffer);
    let end = offset;
    while (buffer[end] !== 0) {
        end++;
        if (end - offset > 10000) break;
    }
    return new TextDecoder('utf-8').decode(buffer.subarray(offset, end));
}

const importObject = {
    console: {
        print_str: (o) => process.stdout.write(getStringFromMem(o)),
        print_i32: (v) => process.stdout.write(v.toString()),
        print_f32: (v) => process.stdout.write(v.toString()),
        log:       (v) => process.stdout.write(v.toString())
    },
    env: {}
};

WebAssembly.instantiate(wasmBuffer, importObject)
    .then(obj => {
        const instance = obj.instance;
        wasmMemory = instance.exports.memory;
        if (instance.exports.main) instance.exports.main();
    })
    .catch(err => {
        console.error("Runtime Error:", err);
        process.exit(1);
    });