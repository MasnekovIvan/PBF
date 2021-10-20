#include <napi.h>
#include <string>

int prev_num = 0;
int next_num = 1;

Napi::String get_next_fib(const Napi::CallbackInfo &info)
{
    Napi::Env env = info.Env();

    int temp = prev_num;
    prev_num = next_num;
    next_num = temp + next_num;

    return Napi::String::New(env, std::to_string(temp));
}

Napi::Object init(Napi::Env env, Napi::Object exports)
{
    exports.Set(Napi::String::New(env, "get"), Napi::Function::New(env, get_next_fib));
    return exports;
};

NODE_API_MODULE(fibonacci, init);