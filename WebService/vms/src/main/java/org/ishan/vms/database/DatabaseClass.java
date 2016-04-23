package org.ishan.vms.database;

import org.ishan.vms.model.*;
import java.util.HashMap;

public class DatabaseClass {
	
	private static HashMap<Long, Data> datas = new HashMap<>();
	
	public static HashMap<Long, Data> getData(){
			return datas;
	}
	private static HashMap<Long, GPSData> GPSdatas = new HashMap<>();
	
	public static HashMap<Long, GPSData> getGPSData(){
			return GPSdatas;
	}
	
}
