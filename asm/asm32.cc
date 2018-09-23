#include "binheader.h"

using namespace std;
using namespace asmjit;
using namespace asmtk;

void my_func(int p) { std::printf("----> %d\n",p); }
void my_func2(void) {
    std::printf("Hello World !!!\n");
    std::printf("numser: %d\n", 1212); exit(2150);
}

void my_func3(char *p) {
    printf("---> %s\n",p);
}

void MyCodeEmitter::emitTest()
{
//    const auto addr  = reinterpret_cast<size_t>  (&my_func3);
//    const auto addr2 = reinterpret_cast<size_t>  (&my_func2);
    
//    asmjit::Label L1 = x86_compiler.newLabel();
//    asmjit::Label L2 = x86_compiler.newLabel();
//    asmjit::Label L3 = x86_compiler.newLabel();
    
//    const char* text = "Hello Computer\n";
    
    x86_compiler.addFunc(FuncSignature0<int>(asmjit::CallConv::kIdHost));
    
    asmjit::X86Gp  v0 = x86_compiler.newGpd("v0");
    asmjit::X86Mem c0 = x86_compiler.newInt32Const(kConstScopeLocal, 200);
    
    x86_compiler.mov(v0,c0);
    x86_compiler.ret(v0);
    
    x86_compiler.endFunc();
    
#if 0
    x86_emitter->nop ();
    x86_emitter->push(x86::rbp);
    x86_emitter->mov (x86::rbp, x86::rsp);
    x86_emitter->sub (x86::rsp, 16);

    x86_emitter->mov (x86::rbx, addr+16);
    x86_emitter->lea (x86::rax, x86::ptr(L1));
    x86_emitter->call(x86::rbx);
    
    
    x86_emitter->mov (x86::rbx, x86::ptr(L2));
    x86_emitter->jmp (x86::rbx);
    

    x86_emitter->bind(L3);
    

    x86_emitter->add (x86::rsp, 16);
    x86_emitter->mov (x86::rsp, x86::rbp);    
    x86_emitter->pop (x86::rbp);
    x86_emitter->ret();
    
    x86_emitter->nop ();
    x86_emitter->nop ();
    x86_emitter->nop ();
    
    x86_emitter->bind (L1);
    x86_emitter->embed(text, strlen(text)+1);
    
    
    //
    x86_emitter->bind(L2);
    
    x86_emitter->mov (x86::rbx, addr+16);
    x86_emitter->lea (x86::rax, x86::ptr(L1));
    x86_emitter->call(x86::rbx);
    
    x86_emitter->jmp (x86::ptr(L3));
#endif
}

MyCodeEmitter::MyCodeEmitter(std::string _name)
{
    lib_name = _name;
    
    // write code ...
    x86_codeholder.init(x86_runtime.getCodeInfo());
    
    x86_codeholder.attach(&x86_compiler);
    x86_emitter = x86_compiler.asEmitter();
    
    emitTest();
}

void MyCodeEmitter::write()
{
    x86_compiler.finalize();

    // save code ...
    CodeBuffer & buffer = x86_codeholder.getSectionEntry(0)->getBuffer();
    uint64_t code_len   = buffer.getLength();

    MyHeaderWriter hw(lib_name,code_len,
    buffer.getData());
    hw.write_data();
    
    x86_codeholder.detach(&x86_compiler);
}
