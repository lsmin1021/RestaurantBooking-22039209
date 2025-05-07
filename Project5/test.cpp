#include "gmock/gmock.h"
#include "booking_scheduler.cpp"

using namespace testing;

class BookingItem : public Test {
protected:
	void SetUp() override {
		NOT_ON_THE_HOUR = getTime(2021, 3, 26, 9, 5);
		ON_THE_HOUR = getTime(2021, 3, 26, 9, 0);
	}
public:
	tm getTime(int year, int mon, int day, int hour, int min) {
		tm result = { 0,min,hour,day,mon - 1,year - 1900,0,0,-1 };
		mktime(&result);
		return result;
	}
	tm NOT_ON_THE_HOUR;
	tm ON_THE_HOUR;
	Customer CUSTOMER{ "fake name", "010-1234-5678" };

	const int UNDER_CAPACITY = 1;
	const int CAPACITY_PER_HOUR = 3;

	BookingScheduler bookingScheduler{ CAPACITY_PER_HOUR };

};

TEST_F(BookingItem, ���������ÿ��������ϴ����ð��ƴѰ�쿹��Ұ�) {
	Schedule* schedule = new Schedule{ NOT_ON_THE_HOUR, UNDER_CAPACITY, CUSTOMER };

	EXPECT_THROW({
		bookingScheduler.addSchedule(schedule);
		}, std::runtime_error);
}

TEST_F(BookingItem, ���������ÿ��������ϴ������ΰ�쿹�డ��) {
	Schedule* schedule = new Schedule{ ON_THE_HOUR, UNDER_CAPACITY, CUSTOMER };

	bookingScheduler.addSchedule(schedule);
	EXPECT_EQ(true, bookingScheduler.hasSchedule(schedule));
}

TEST_F(BookingItem, �ð��뺰�ο��������ִٰ����ð��뿡Capacity�ʰ��Ұ�쿹�ܹ߻�) {

}

TEST_F(BookingItem, �ð��뺰�ο��������ִٰ����ð��밡�ٸ���Capacity���־�������߰�����) {

}

TEST_F(BookingItem, ����Ϸ��SMS�¹����ǹ߼�) {

}

TEST_F(BookingItem, �̸����̾��°�쿡���̸��Ϲ̹߼�) {

}

TEST_F(BookingItem, �̸������ִ°�쿡���̸��Ϲ߼�) {

}

TEST_F(BookingItem, ���糯¥���Ͽ����ΰ�쿹��Ұ�����ó��) {

}

TEST_F(BookingItem, ���糯¥���Ͽ����̾ƴѰ�쿹�డ��) {

}

int main() {
	::testing::InitGoogleMock();
	return RUN_ALL_TESTS();
}