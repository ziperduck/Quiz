#pragma once

//타입 파라미터에 typename과 class는 하는 일을 같습니다.
//인자값으로 타입을 제공하면 됩니다.
//하지만 typename은 타입을 class는 클래스를 전달하라고 알려주는 기능으로 사용합니다.
//int처럼 정확한 타입을 명시할 경우 타입에 맞는 값을 전달해주면 됩니다.

template<int A, int B>
struct GCD
{
	static const int result = GCD<B, A % B>::result;
};

//템플릿 특수화입니다.
template<int A>
//GCD<>에 입력되는 B값이 0일경우 해당 
//밑에서부터 내려와서 false가 나올때까지 작동하느지 확인하자
struct GCD<A, 0>
{
	static const int result = A;
};

void Metaprograming();