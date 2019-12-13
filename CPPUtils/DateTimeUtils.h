
#ifndef __DateTimeUtils_H__
#define __DateTimeUtils_H__

#include <time.h>
#include <string>

#define DATA_TIME_BUF 128

#define BST (+1)//伦敦
#define CCT (+8)//中国


class DateTimeUtils {
public:
	//getCurrentDate 2019-12-04
	static std::string getCurrentDate() {
		static char buf[DATA_TIME_BUF];
		time_t ctime = time(NULL);
		strftime(buf, DATA_TIME_BUF, "%Y-%m-%d", localtime(&ctime));
		return buf;
	}

	//getCurrentTime 23:03:04	
	static std::string getCurrentTime() {
		static char buf[DATA_TIME_BUF];
		time_t ctime = time(NULL);
		strftime(buf, DATA_TIME_BUF, "%H:%M:%S", localtime(&ctime));
		return buf;
	}

	//getCurrentDateTime 2019-12-04 23:03:04
	static std::string getCurrentDateTime() {
		static char buf[DATA_TIME_BUF];
		time_t ctime = time(NULL);
		strftime(buf, DATA_TIME_BUF, "%Y-%m-%d %X", localtime(&ctime));
		return buf;
	}

	//getGMTDateTime Tue, 03 Dec 2019 13:15:10 GMT
	static std::string getGMTDateTime() {
		static char buf[DATA_TIME_BUF];
		time_t ctime = time(NULL);
		strftime(buf, 127, "%a, %d %b %Y %X", gmtime(&ctime));
		return buf;
	}

	//打印本本地时间和格林时间
	static void DateTime() {
		time_t ctime = time(NULL);
		struct tm *tmgm = gmtime(&ctime);

		printf("%d年%d月%d日 %d:%d:%d\n",
			tmgm->tm_year+1900, tmgm->tm_mon+1, tmgm->tm_mday,
			tmgm->tm_hour, tmgm->tm_min, tmgm->tm_sec);
		printf("%s", asctime(tmgm));

		struct tm *tmlocal = localtime(&ctime);
		printf("%d年%d月%d日 %d:%d:%d\n",
			tmlocal->tm_year + 1900, tmlocal->tm_mon+1, tmlocal->tm_mday,
			tmlocal->tm_hour, tmlocal->tm_min, tmlocal->tm_sec);
		printf("%s", asctime(tmlocal));
	}
private:
	DateTimeUtils();//单例类
};


#endif
