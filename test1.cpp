#include "doctest.h"
#include "MedianStruct.h"

//#include <unistd.h>


SCENARIO("sleep a second") {

  GIVEN("a one second sleep duration") {

	  MedianStruct medS;

	  CHECK(medS.GetMedian() == 0.0);


	  medS.Add(1);
	  CHECK(medS.GetMedian() == 1.0);

	  medS.Add(101);
	  CHECK(medS.GetMedian() == 51.0);

	  for (int i = 0; i < 100; i++)
	  {
		  medS.Add(10);
		  CHECK(medS.GetMedian() == 10.0);
	  }


	  MedianStruct medS2;

	  for (int i = 0; i < 10; i++)
	  {
		  medS2.Add(30);
		  CHECK(medS2.GetMedian() == 30.0);
	  }

	  for (int i = 0; i < 20; i++)
	  {
		  medS2.Add(40);
		  if (i < 9)
		  {
			  CHECK(medS2.GetMedian() == 30.0);
		  }
		  else if (i < 10)
		  {
			  CHECK(medS2.GetMedian() == 35.0);
		  }
		  else
		  {
			  CHECK(medS2.GetMedian() == 40.0);
		  }
	  }

    unsigned int duration =1 ;

    WHEN("call sleep with this duration") {
      int ret = 0 ;

      THEN("it's expected nobody interupted our rest") {
        CHECK(ret == 0);
      }
    }
  }
} 
