#include "ReturnShared.h"

std::shared_ptr<SharedClass> GetShared_ptr()
{
	static OneShared* one = new OneShared(2);

	static TwoShared* two = new TwoShared();
	
	return std::make_shared<SharedClass>(one, two);
}

void TestReturnMakeShared()
{
	std::shared_ptr<SharedClass> ptr = GetShared_ptr();

	printf("ptr count = %d\n", ptr.use_count());

	if (ptr.use_count() > 0)
	{
		ptr->printnum();
	}

}
