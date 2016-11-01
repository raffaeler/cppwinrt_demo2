#pragma once

#include <winrt\base.h>

template <typename Trt, typename CX>
CX copyCX(const Trt& rt)
{
    auto abi = winrt::get(rt);
    auto cx = reinterpret_cast<CX>(abi);
    return cx;
}

template <typename Trtabi, typename CX, typename Trt>
Trt copyRT(CX cx)
{
    auto abi = reinterpret_cast<Trtabi>(cx);
    Trt res(nullptr);
    winrt::copy_from(res, abi);
    return res;
}
//
//template <typename Trtabi, typename CX, typename Trt>
//Trt copyRT2(CX cx)
//{
//    auto abi = reinterpret_cast<Trtabi>(cx);
//    Trt res(nullptr);
//    winrt::copy_from(res, abi);
//    return res.as<Rrt>();
//}