#include<iostream>
#include<string>
#include<iomanip>
#include<cmath>

using namespace std;
int main()
{
	//INITIALIZING ALL VARIABLES USED IN THE PROGRAM
	double jd;//Julain date
	double year;//Year
	double month;//Month
	double day;//Date
	
	double jc;//Julian centuary
	double gml;//Geometric mean longitude sun(deg)
	double gma;//Geometric mean Anom sun(deg)
	double i;//formula of geometric mean longitude
	double eeo;//Eccent Eart Orbit
	double sec;//Sun Equation Of Centre
	double pi = 3.142857;
	double stl;//Sun True Longitude (degree)
	double sta;//Sun True Anom (degree)
	double srv;//Sun Rad Vector(AUs)
	double sal;//Sun App Longitude(degress)
	double moe;//Mean Obliq Ecliptic(degrees)
	double oc;//Obliq Corr(degree)
	double sra;//Sun Rt Ascen(degrees)
	double sd;//Sun decline(degree)
	double vy;//Var y
	double eot;//Equation of time
	double has;//HA sunrise (degree)
	double sn;//Solar Noon(LST)
	double sr;//Sun Rise
	double ss;//Sun set
	double rad = pi / 180;//radians
	int z4;
	int m = 0;

	//data entry
	
	cout << "********************************************PROGRAM FOR SUN RISE AND SUNSET********************************************" << endl;
	cout << "Press 1 to calculate the time for sunrise and sunset in Taxila" << endl;
	cout << "Press 2 to calculate the time for sunrise and sunset in  london" << endl;
	cout << "Press 3 to calculate the time for sunrise and sunset in  Karachi" << endl;
	cout << "Press 4 to calculate the time for sunrise and sunset in  Peshawar" << endl;
	cout << "Press 5 to calculate the time for sunrise and sunset in  Lahore" << endl;
	cout << "Press 6 to calculate the time for sunrise and sunset for Anywhere in the world" << endl;
	cin >> m;
	if (m == 1)
	{
		double longitude = 72.81841;//longitude
		double latitude = 33.74604;//latitude
		double timezone=5;//timezone

		cout << "\nEnter the year : \n";
		cin >> year;
		cout << "Enter the desired month : \n";
		cin >> month;
		cout << "Enter the desired Date : \n";
		cin >> day;
		//cout << "Enter latitude of the place:                                                     (Note: latitude will be from N to S)" << endl;
		//cin >> latitude;
		//cout << "Enter longitude of the place:                                                    (Note: longitude will be from E to W)" << endl;
		//cin >> longitude;
		//cout << "Enter timezone: " << endl;
		//cin >> timezone;

		cout << fixed << showpoint;
		//Julian Date
		jd = (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;


		//Julian centuary
		jc = (jd - 2451545) / 36525;//Formula for julian century



		//formula of geometric mean longitude
		i = (280.46646 + jc * (36000.76983 + jc * 0.0003032));
		cout << fixed << showpoint;

		//Geometric mean longitude sun(deg)
		gml = fmod(i, 360);


		//Geometric mean Anom sun(deg)
		gma = 357.52911 + jc * (35999.05029 - 0.0001537 * jc);


		// Eccent Eart Orbit
		eeo = 0.016708634 - jc * (0.000042037 + 0.0000001267 * jc);


		//Sun Equation Of Centre
		sec = sin(gma * rad) * (1.914602 - jc * (0.004817 + 0.000014 * jc)) + sin(2 * gma * rad) * (0.019993 - 0.000101 * jc) + sin(3 * gma * rad) * 0.000289;


		//Sun True Longitude (degree)
		stl = gml + sec;


		//Sun True Anom (degree)
		sta = gma + sec;


		//Sun Radian Vector(AUs)
		srv = (1.000001018 * (1 - eeo * eeo)) / (1 + eeo * cos(sta * rad));


		//Sun App Longitude(degress)
		sal = stl - 0.00569 - 0.00478 * sin((125.04 - 1934.136 * jc) * rad);


		//Mean Obliq Ecliptic(degrees)
		moe = 23 + (26 + ((21.448 - jc * (46.815 + jc * (0.00059 - jc * 0.001813)))) / 60) / 60;


		//Obliq Corr(degree)
		oc = moe + 0.00256 * cos((125.04 - 1934.136 * jc) * rad);


		//Sun Rt Ascen(degrees)
		sra = (atan2(cos(oc * rad) * sin(sal * rad), cos(sal * rad))) * 180 / pi; //syntax is change in excel and in c++. Syntax in c++ = atan2(y,x) and in excel it is atan2(x,).


		//Sun decline(degree)
		sd = (asin(sin(oc * rad)) * sin(sal * rad)) * 180 / pi;


		//Var y
		vy = tan((oc / 2) * rad) * tan((oc / 2) * rad);


		//Equation of time
		eot = ((vy * sin(2 * gml * rad)) - 2 * eeo * sin(gma * rad) + 4 * eeo * vy * sin(gma * rad) * cos(2 * gml * rad) - 0.5 * vy * vy * sin(4 * gml * rad) - 1.25 * eeo * eeo * sin(2 * gma * rad)) * 4 * 180 / pi;


		//HA sunrise (degree)
		has = (acos(cos(90.833 * rad) / (cos(latitude * rad) * cos(sd * rad)) - tan(latitude * rad) * tan(sd * rad))) * 180 / pi;


		//Solar Noon(LST)
		sn = (720 - 4 * longitude - eot + timezone * 60) / 1440;


		//Sun Rise
		sr = (sn * 1440 - has * 4) / 1440;



		//Sun Set
		ss = (sn * 1440.0 + has * 4.0) / 1440.0;


		//time sunrise
		double hr1;
		int aa;
		double ab;
		double e;
		double aq;
		int aqq;
		hr1 = sr * 24;
		aa = hr1;//hours

		e = hr1 - aa;
		aq = e * 60;
		aqq = aq;//minutes


		double ee;
		double ef;
		int af;
		ee = aq - aqq;
		ef = ee * 60;
		af = ef;//sec

		cout << "Time for sun rise in Taxila : " << aa << ":" << aqq << ":" << af << endl;

		//time Sun set

		double hr2;
		int aa1;
		double ab1;
		double e1;
		double aq1;
		int aqq1;
		hr2 = ss * 24;
		aa1 = hr2;//hours

		e1 = hr2 - aa1;
		aq1 = e1 * 60;
		aqq1 = aq1;//minutes


		double ee1;
		double ef1;
		int af1;
		ee1 = aq1 - aqq1;
		ef1 = ee1 * 60;
		af1 = ef1;//sec

		cout << "Time for sun set in Taxila : " << aa1 << ":" << aqq1 << ":" << af1 << endl;

		
		
		
	}
	if (m == 2)
	{
		double longitude = 0.1278;//longitude
		double latitude = 51.5047;//latitude
		double timezone = 1;//timezone 

		cout << "\nEnter the year : \n";
		cin >> year;
		cout << "Enter the desired month : \n";
		cin >> month;
		cout << "Enter the desired Date : \n";
		cin >> day;
		/*cout << "Enter latitude of the place:                                                     (Note: latitude will be from N to S)" << endl;
		//cin >> latitude;
		cout << "Enter longitude of the place:                                                    (Note: longitude will be from E to W)" << endl;
		//cin >> longitude;
		cout << "Enter timezone: " << endl;
		//cin >> timezone;*/

		cout << fixed << showpoint;
		//Julian Date
		jd = (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;


		//Julian centuary
		jc = (jd - 2451545) / 36525;//Formula for julian century



		//formula of geometric mean longitude
		i = (280.46646 + jc * (36000.76983 + jc * 0.0003032));
		cout << fixed << showpoint;

		//Geometric mean longitude sun(deg)
		gml = fmod(i, 360);


		//Geometric mean Anom sun(deg)
		gma = 357.52911 + jc * (35999.05029 - 0.0001537 * jc);


		// Eccent Eart Orbit
		eeo = 0.016708634 - jc * (0.000042037 + 0.0000001267 * jc);


		//Sun Equation Of Centre
		sec = sin(gma * rad) * (1.914602 - jc * (0.004817 + 0.000014 * jc)) + sin(2 * gma * rad) * (0.019993 - 0.000101 * jc) + sin(3 * gma * rad) * 0.000289;


		//Sun True Longitude (degree)
		stl = gml + sec;


		//Sun True Anom (degree)
		sta = gma + sec;


		//Sun Radian Vector(AUs)
		srv = (1.000001018 * (1 - eeo * eeo)) / (1 + eeo * cos(sta * rad));


		//Sun App Longitude(degress)
		sal = stl - 0.00569 - 0.00478 * sin((125.04 - 1934.136 * jc) * rad);


		//Mean Obliq Ecliptic(degrees)
		moe = 23 + (26 + ((21.448 - jc * (46.815 + jc * (0.00059 - jc * 0.001813)))) / 60) / 60;


		//Obliq Corr(degree)
		oc = moe + 0.00256 * cos((125.04 - 1934.136 * jc) * rad);


		//Sun Rt Ascen(degrees)
		sra = (atan2(cos(oc * rad) * sin(sal * rad), cos(sal * rad))) * 180 / pi; //syntax is change in excel and in c++. Syntax in c++ = atan2(y,x) and in excel it is atan2(x,).


		//Sun decline(degree)
		sd = (asin(sin(oc * rad)) * sin(sal * rad)) * 180 / pi;


		//Var y
		vy = tan((oc / 2) * rad) * tan((oc / 2) * rad);


		//Equation of time
		eot = ((vy * sin(2 * gml * rad)) - 2 * eeo * sin(gma * rad) + 4 * eeo * vy * sin(gma * rad) * cos(2 * gml * rad) - 0.5 * vy * vy * sin(4 * gml * rad) - 1.25 * eeo * eeo * sin(2 * gma * rad)) * 4 * 180 / pi;


		//HA sunrise (degree)
		has = (acos(cos(90.833 * rad) / (cos(latitude * rad) * cos(sd * rad)) - tan(latitude * rad) * tan(sd * rad))) * 180 / pi;


		//Solar Noon(LST)
		sn = (720 - 4 * longitude - eot + timezone * 60) / 1440;


		//Sun Rise
		sr = (sn * 1440 - has * 4) / 1440;



		//Sun Set
		ss = (sn * 1440.0 + has * 4.0) / 1440.0;


		//time sunrise
		double hr1;
		int aa;
		double ab;
		double e;
		double aq;
		int aqq;
		hr1 = sr * 24;
		aa = hr1;//hours

		e = hr1 - aa;
		aq = e * 60;
		aqq = aq;//minutes


		double ee;
		double ef;
		int af;
		ee = aq - aqq;
		ef = ee * 60;
		af = ef;//sec

		cout << "Time for sun rise in london is : " << aa << ":" << aqq << ":" << af << endl;

		//time Sun set

		double hr2;
		int aa1;
		double ab1;
		double e1;
		double aq1;
		int aqq1;
		hr2 = ss * 24;
		aa1 = hr2;//hours

		e1 = hr2 - aa1;
		aq1 = e1 * 60;
		aqq1 = aq1;//minutes


		double ee1;
		double ef1;
		int af1;
		ee1 = aq1 - aqq1;
		ef1 = ee1 * 60;
		af1 = ef1;//sec

		cout << "Time for sun set in London is : " << aa1 << ":" << aqq1 << ":" << af1 << endl;

		
	}
		if (m == 3)
		{

			double longitude = 67.0011;//longitude
			double latitude = 24.8607;//latitude
			double timezone = 5;//timezone

			cout << "\nEnter the year : \n";
			cin >> year;
			cout << "Enter the desired month : \n";
			cin >> month;
			cout << "Enter the desired Date : \n";
			cin >> day;
			/*cout << "Enter latitude of the place:                                                     (Note: latitude will be from N to S)" << endl;
			//cin >> latitude;
			cout << "Enter longitude of the place:                                                    (Note: longitude will be from E to W)" << endl;
			//cin >> longitude;
			cout << "Enter timezone: " << endl;
			//cin >> timezone;*/

			cout << fixed << showpoint;
			//Julian Date
			jd = (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;


			//Julian centuary
			jc = (jd - 2451545) / 36525;//Formula for julian century



			//formula of geometric mean longitude
			i = (280.46646 + jc * (36000.76983 + jc * 0.0003032));
			cout << fixed << showpoint;

			//Geometric mean longitude sun(deg)
			gml = fmod(i, 360);


			//Geometric mean Anom sun(deg)
			gma = 357.52911 + jc * (35999.05029 - 0.0001537 * jc);


			// Eccent Eart Orbit
			eeo = 0.016708634 - jc * (0.000042037 + 0.0000001267 * jc);


			//Sun Equation Of Centre
			sec = sin(gma * rad) * (1.914602 - jc * (0.004817 + 0.000014 * jc)) + sin(2 * gma * rad) * (0.019993 - 0.000101 * jc) + sin(3 * gma * rad) * 0.000289;


			//Sun True Longitude (degree)
			stl = gml + sec;


			//Sun True Anom (degree)
			sta = gma + sec;


			//Sun Radian Vector(AUs)
			srv = (1.000001018 * (1 - eeo * eeo)) / (1 + eeo * cos(sta * rad));


			//Sun App Longitude(degress)
			sal = stl - 0.00569 - 0.00478 * sin((125.04 - 1934.136 * jc) * rad);


			//Mean Obliq Ecliptic(degrees)
			moe = 23 + (26 + ((21.448 - jc * (46.815 + jc * (0.00059 - jc * 0.001813)))) / 60) / 60;


			//Obliq Corr(degree)
			oc = moe + 0.00256 * cos((125.04 - 1934.136 * jc) * rad);


			//Sun Rt Ascen(degrees)
			sra = (atan2(cos(oc * rad) * sin(sal * rad), cos(sal * rad))) * 180 / pi; //syntax is change in excel and in c++. Syntax in c++ = atan2(y,x) and in excel it is atan2(x,).


			//Sun decline(degree)
			sd = (asin(sin(oc * rad)) * sin(sal * rad)) * 180 / pi;


			//Var y
			vy = tan((oc / 2) * rad) * tan((oc / 2) * rad);


			//Equation of time
			eot = ((vy * sin(2 * gml * rad)) - 2 * eeo * sin(gma * rad) + 4 * eeo * vy * sin(gma * rad) * cos(2 * gml * rad) - 0.5 * vy * vy * sin(4 * gml * rad) - 1.25 * eeo * eeo * sin(2 * gma * rad)) * 4 * 180 / pi;


			//HA sunrise (degree)
			has = (acos(cos(90.833 * rad) / (cos(latitude * rad) * cos(sd * rad)) - tan(latitude * rad) * tan(sd * rad))) * 180 / pi;


			//Solar Noon(LST)
			sn = (720 - 4 * longitude - eot + timezone * 60) / 1440;


			//Sun Rise
			sr = (sn * 1440 - has * 4) / 1440;



			//Sun Set
			ss = (sn * 1440.0 + has * 4.0) / 1440.0;


			//time sunrise
			double hr1;
			int aa;
			double ab;
			double e;
			double aq;
			int aqq;
			hr1 = sr * 24;
			aa = hr1;//hours

			e = hr1 - aa;
			aq = e * 60;
			aqq = aq;//minutes


			double ee;
			double ef;
			int af;
			ee = aq - aqq;
			ef = ee * 60;
			af = ef;//sec

			cout << "Time for sun rise in Karachi is : " << aa << ":" << aqq << ":" << af << endl;

			//time Sun set

			double hr2;
			int aa1;
			double ab1;
			double e1;
			double aq1;
			int aqq1;
			hr2 = ss * 24;
			aa1 = hr2;//hours

			e1 = hr2 - aa1;
			aq1 = e1 * 60;
			aqq1 = aq1;//minutes


			double ee1;
			double ef1;
			int af1;
			ee1 = aq1 - aqq1;
			ef1 = ee1 * 60;
			af1 = ef1;//sec

			cout << "Time for sun set in Karachi is : " << aa1 << ":" << aqq1 << ":" << af1 << endl;

			
		}

		if (m == 4)

		{

			double longitude = 71.5249;//longitude
			double latitude = 34.0151;//latitude
			double timezone = 5;//timezone

			cout << "\nEnter the year : \n";
			cin >> year;
			cout << "Enter the desired month : \n";
			cin >> month;
			cout << "Enter the desired Date : \n";
			cin >> day;
			/*cout << "Enter latitude of the place:                                                     (Note: latitude will be from N to S)" << endl;
			//cin >> latitude;
			cout << "Enter longitude of the place:                                                    (Note: longitude will be from E to W)" << endl;
			//cin >> longitude;
			cout << "Enter timezone: " << endl;
			//cin >> timezone;*/

			cout << fixed << showpoint;
			//Julian Date
			jd = (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;


			//Julian centuary
			jc = (jd - 2451545) / 36525;//Formula for julian century



			//formula of geometric mean longitude
			i = (280.46646 + jc * (36000.76983 + jc * 0.0003032));
			cout << fixed << showpoint;

			//Geometric mean longitude sun(deg)
			gml = fmod(i, 360);


			//Geometric mean Anom sun(deg)
			gma = 357.52911 + jc * (35999.05029 - 0.0001537 * jc);


			// Eccent Eart Orbit
			eeo = 0.016708634 - jc * (0.000042037 + 0.0000001267 * jc);


			//Sun Equation Of Centre
			sec = sin(gma * rad) * (1.914602 - jc * (0.004817 + 0.000014 * jc)) + sin(2 * gma * rad) * (0.019993 - 0.000101 * jc) + sin(3 * gma * rad) * 0.000289;


			//Sun True Longitude (degree)
			stl = gml + sec;


			//Sun True Anom (degree)
			sta = gma + sec;


			//Sun Radian Vector(AUs)
			srv = (1.000001018 * (1 - eeo * eeo)) / (1 + eeo * cos(sta * rad));


			//Sun App Longitude(degress)
			sal = stl - 0.00569 - 0.00478 * sin((125.04 - 1934.136 * jc) * rad);


			//Mean Obliq Ecliptic(degrees)
			moe = 23 + (26 + ((21.448 - jc * (46.815 + jc * (0.00059 - jc * 0.001813)))) / 60) / 60;


			//Obliq Corr(degree)
			oc = moe + 0.00256 * cos((125.04 - 1934.136 * jc) * rad);


			//Sun Rt Ascen(degrees)
			sra = (atan2(cos(oc * rad) * sin(sal * rad), cos(sal * rad))) * 180 / pi; //syntax is change in excel and in c++. Syntax in c++ = atan2(y,x) and in excel it is atan2(x,).


			//Sun decline(degree)
			sd = (asin(sin(oc * rad)) * sin(sal * rad)) * 180 / pi;


			//Var y
			vy = tan((oc / 2) * rad) * tan((oc / 2) * rad);


			//Equation of time
			eot = ((vy * sin(2 * gml * rad)) - 2 * eeo * sin(gma * rad) + 4 * eeo * vy * sin(gma * rad) * cos(2 * gml * rad) - 0.5 * vy * vy * sin(4 * gml * rad) - 1.25 * eeo * eeo * sin(2 * gma * rad)) * 4 * 180 / pi;


			//HA sunrise (degree)
			has = (acos(cos(90.833 * rad) / (cos(latitude * rad) * cos(sd * rad)) - tan(latitude * rad) * tan(sd * rad))) * 180 / pi;


			//Solar Noon(LST)
			sn = (720 - 4 * longitude - eot + timezone * 60) / 1440;


			//Sun Rise
			sr = (sn * 1440 - has * 4) / 1440;



			//Sun Set
			ss = (sn * 1440.0 + has * 4.0) / 1440.0;


			//time sunrise
			double hr1;
			int aa;
			double ab;
			double e;
			double aq;
			int aqq;
			hr1 = sr * 24;
			aa = hr1;//hours

			e = hr1 - aa;
			aq = e * 60;
			aqq = aq;//minutes


			double ee;
			double ef;
			int af;
			ee = aq - aqq;
			ef = ee * 60;
			af = ef;//sec

			cout << "Time for sun rise in Peshawar is : " << aa << ":" << aqq << ":" << af << endl;

			//time Sun set

			double hr2;
			int aa1;
			double ab1;
			double e1;
			double aq1;
			int aqq1;
			hr2 = ss * 24;
			aa1 = hr2;//hours

			e1 = hr2 - aa1;
			aq1 = e1 * 60;
			aqq1 = aq1;//minutes


			double ee1;
			double ef1;
			int af1;
			ee1 = aq1 - aqq1;
			ef1 = ee1 * 60;
			af1 = ef1;//sec

			cout << "Time for sun set in Peshawar is : " << aa1 << ":" << aqq1 << ":" << af1 << endl;

			
	}

	if (m == 5)
	{

		double longitude = 74.3587;//longitude
		double latitude = 31.5204;//latitude
		double timezone = 5;//timezone

		cout << "\nEnter the year : \n";
		cin >> year;
		cout << "Enter the desired month : \n";
		cin >> month;
		cout << "Enter the desired Date : \n";
		cin >> day;
		//cout << "Enter latitude of the place:                                                     (Note: latitude will be from N to S)" << endl;
		//cin >> latitude;
		//ut << "Enter longitude of the place:                                                    (Note: longitude will be from E to W)" << endl;
		//cin >> longitude;
		//ut << "Enter timezone: " << endl;
		//cin >> timezone;

		cout << fixed << showpoint;
		//Julian Date
		jd = (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;


		//Julian centuary
		jc = (jd - 2451545) / 36525;//Formula for julian century



		//formula of geometric mean longitude
		i = (280.46646 + jc * (36000.76983 + jc * 0.0003032));
		cout << fixed << showpoint;

		//Geometric mean longitude sun(deg)
		gml = fmod(i, 360);


		//Geometric mean Anom sun(deg)
		gma = 357.52911 + jc * (35999.05029 - 0.0001537 * jc);


		// Eccent Eart Orbit
		eeo = 0.016708634 - jc * (0.000042037 + 0.0000001267 * jc);


		//Sun Equation Of Centre
		sec = sin(gma * rad) * (1.914602 - jc * (0.004817 + 0.000014 * jc)) + sin(2 * gma * rad) * (0.019993 - 0.000101 * jc) + sin(3 * gma * rad) * 0.000289;


		//Sun True Longitude (degree)
		stl = gml + sec;


		//Sun True Anom (degree)
		sta = gma + sec;


		//Sun Radian Vector(AUs)
		srv = (1.000001018 * (1 - eeo * eeo)) / (1 + eeo * cos(sta * rad));


		//Sun App Longitude(degress)
		sal = stl - 0.00569 - 0.00478 * sin((125.04 - 1934.136 * jc) * rad);


		//Mean Obliq Ecliptic(degrees)
		moe = 23 + (26 + ((21.448 - jc * (46.815 + jc * (0.00059 - jc * 0.001813)))) / 60) / 60;


		//Obliq Corr(degree)
		oc = moe + 0.00256 * cos((125.04 - 1934.136 * jc) * rad);


		//Sun Rt Ascen(degrees)
		sra = (atan2(cos(oc * rad) * sin(sal * rad), cos(sal * rad))) * 180 / pi; //syntax is change in excel and in c++. Syntax in c++ = atan2(y,x) and in excel it is atan2(x,).


		//Sun decline(degree)
		sd = (asin(sin(oc * rad)) * sin(sal * rad)) * 180 / pi;


		//Var y
		vy = tan((oc / 2) * rad) * tan((oc / 2) * rad);


		//Equation of time
		eot = ((vy * sin(2 * gml * rad)) - 2 * eeo * sin(gma * rad) + 4 * eeo * vy * sin(gma * rad) * cos(2 * gml * rad) - 0.5 * vy * vy * sin(4 * gml * rad) - 1.25 * eeo * eeo * sin(2 * gma * rad)) * 4 * 180 / pi;


		//HA sunrise (degree)
		has = (acos(cos(90.833 * rad) / (cos(latitude * rad) * cos(sd * rad)) - tan(latitude * rad) * tan(sd * rad))) * 180 / pi;


		//Solar Noon(LST)
		sn = (720 - 4 * longitude - eot + timezone * 60) / 1440;


		//Sun Rise
		sr = (sn * 1440 - has * 4) / 1440;



		//Sun Set
		ss = (sn * 1440.0 + has * 4.0) / 1440.0;


		//time sunrise
		double hr1;
		int aa;
		double ab;
		double e;
		double aq;
		int aqq;
		hr1 = sr * 24;
		aa = hr1;//hours

		e = hr1 - aa;
		aq = e * 60;
		aqq = aq;//minutes


		double ee;
		double ef;
		int af;
		ee = aq - aqq;
		ef = ee * 60;
		af = ef;//sec

		cout << "Time for sun rise in Lahore : " << aa << ":" << aqq << ":" << af << endl;

		//time Sun set

		double hr2;
		int aa1;
		double ab1;
		double e1;
		double aq1;
		int aqq1;
		hr2 = ss * 24;
		aa1 = hr2;//hours

		e1 = hr2 - aa1;
		aq1 = e1 * 60;
		aqq1 = aq1;//minutes


		double ee1;
		double ef1;
		int af1;
		ee1 = aq1 - aqq1;
		ef1 = ee1 * 60;
		af1 = ef1;//sec

		cout << "Time for sun set in Lahore : " << aa1 << ":" << aqq1 << ":" << af1 << endl;

		

	}
	

	if (m == 6)

	{
		double longitude ;//longitude
		double latitude ;//latitude
		double timezone ;//timezone

		cout << "\nEnter the year : \n";
		cin >> year;
		cout << "Enter the desired month : \n";
		cin >> month;
		cout << "Enter the desired Date : \n";
		cin >> day;
		cout << "Enter latitude of the place:                                                     (Note: latitude will be from N to S)" << endl;
		cin >> latitude;
		cout << "Enter longitude of the place:                                                    (Note: longitude will be from E to W)" << endl;
		cin >> longitude;
		cout << "Enter timezone: " << endl;
		cin >> timezone;

		cout << fixed << showpoint;
		//Julian Date
		jd = (1461 * (year + 4800 + (month - 14) / 12)) / 4 + (367 * (month - 2 - 12 * ((month - 14) / 12))) / 12 - (3 * ((year + 4900 + (month - 14) / 12) / 100)) / 4 + day - 32075;


		//Julian centuary
		jc = (jd - 2451545) / 36525;//Formula for julian century



		//formula of geometric mean longitude
		i = (280.46646 + jc * (36000.76983 + jc * 0.0003032));
		cout << fixed << showpoint;

		//Geometric mean longitude sun(deg)
		gml = fmod(i, 360);


		//Geometric mean Anom sun(deg)
		gma = 357.52911 + jc * (35999.05029 - 0.0001537 * jc);


		// Eccent Eart Orbit
		eeo = 0.016708634 - jc * (0.000042037 + 0.0000001267 * jc);


		//Sun Equation Of Centre
		sec = sin(gma * rad) * (1.914602 - jc * (0.004817 + 0.000014 * jc)) + sin(2 * gma * rad) * (0.019993 - 0.000101 * jc) + sin(3 * gma * rad) * 0.000289;


		//Sun True Longitude (degree)
		stl = gml + sec;


		//Sun True Anom (degree)
		sta = gma + sec;


		//Sun Radian Vector(AUs)
		srv = (1.000001018 * (1 - eeo * eeo)) / (1 + eeo * cos(sta * rad));


		//Sun App Longitude(degress)
		sal = stl - 0.00569 - 0.00478 * sin((125.04 - 1934.136 * jc) * rad);


		//Mean Obliq Ecliptic(degrees)
		moe = 23 + (26 + ((21.448 - jc * (46.815 + jc * (0.00059 - jc * 0.001813)))) / 60) / 60;


		//Obliq Corr(degree)
		oc = moe + 0.00256 * cos((125.04 - 1934.136 * jc) * rad);


		//Sun Rt Ascen(degrees)
		sra = (atan2(cos(oc * rad) * sin(sal * rad), cos(sal * rad))) * 180 / pi; //syntax is change in excel and in c++. Syntax in c++ = atan2(y,x) and in excel it is atan2(x,).


		//Sun decline(degree)
		sd = (asin(sin(oc * rad)) * sin(sal * rad)) * 180 / pi;


		//Var y
		vy = tan((oc / 2) * rad) * tan((oc / 2) * rad);


		//Equation of time
		eot = ((vy * sin(2 * gml * rad)) - 2 * eeo * sin(gma * rad) + 4 * eeo * vy * sin(gma * rad) * cos(2 * gml * rad) - 0.5 * vy * vy * sin(4 * gml * rad) - 1.25 * eeo * eeo * sin(2 * gma * rad)) * 4 * 180 / pi;


		//HA sunrise (degree)
		has = (acos(cos(90.833 * rad) / (cos(latitude * rad) * cos(sd * rad)) - tan(latitude * rad) * tan(sd * rad))) * 180 / pi;


		//Solar Noon(LST)
		sn = (720 - 4 * longitude - eot + timezone * 60) / 1440;


		//Sun Rise
		sr = (sn * 1440 - has * 4) / 1440;



		//Sun Set
		ss = (sn * 1440.0 + has * 4.0) / 1440.0;


		//time sunrise
		double hr1;
		int aa;
		double ab;
		double e;
		double aq;
		int aqq;
		hr1 = sr * 24;
		aa = hr1;//hours

		e = hr1 - aa;
		aq = e * 60;
		aqq = aq;//minutes


		double ee;
		double ef;
		int af;
		ee = aq - aqq;
		ef = ee * 60;
		af = ef;//sec

		cout << "Time for sun rise is : " << aa << ":" << aqq << ":" << af << endl;

		//time Sun set

		double hr2;
		int aa1;
		double ab1;
		double e1;
		double aq1;
		int aqq1;
		hr2 = ss * 24;
		aa1 = hr2;//hours

		e1 = hr2 - aa1;
		aq1 = e1 * 60;
		aqq1 = aq1;//minutes


		double ee1;
		double ef1;
		int af1;
		ee1 = aq1 - aqq1;
		ef1 = ee1 * 60;
		af1 = ef1;//sec

		cout << "Time for sun set is : " << aa1 << ":" << aqq1 << ":" << af1 << endl;



	}
	cout << "***********************************************************************************************************************";
	cout << "\n\n\nEnter any DIGIT and press ENTER to finish the program " << endl;
	cin >> z4;
	return 0;

}
