class UndergroundSystem {
public:
  map<pair<string, string>, double> totalTime;
  map<pair<string, string>, double> freqOfTravel;
  map<int, pair<string, int>> idToCheckIn;
  UndergroundSystem() {
    int i=0;
  }

  void checkIn(int id, string stationName, int t) {
    idToCheckIn[id] = {stationName, t};
  }

  void checkOut(int id, string stationName, int t) {
    string checkIn = idToCheckIn[id].first;
    int time = idToCheckIn[id].second;
    freqOfTravel[{checkIn, stationName}]++;
    totalTime[{checkIn, stationName}] += (t-time);
  }

  double getAverageTime(string startStation, string endStation) {
    return (double)(totalTime[{startStation, endStation}]/freqOfTravel[{startStation, endStation}]);
  }
};

/**
 * Your UndergroundSystem object will be instantiated and called as such:
 * UndergroundSystem* obj = new UndergroundSystem();
 * obj->checkIn(id,stationName,t);
 * obj->checkOut(id,stationName,t);
 * double param_3 = obj->getAverageTime(startStation,endStation);
 */