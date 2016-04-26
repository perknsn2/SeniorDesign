package org.ishan.vms.model;

import java.util.Date;
import javax.xml.bind.annotation.*;

@XmlRootElement
public class GPSData {
	
	private long id;
	private float longitude;
	private float latitude;
	private Date date;
	
	public GPSData(){
		
	}
	
	public GPSData(long id, float longitude, float latitude){
		this.id = id;
		this.longitude = longitude;
		this.latitude = latitude;
		this.date = new Date();
	}

	public long getId() {
		return id;
	}

	public void setId(long id) {
		this.id = id;
	}

	public float getLongitude() {
		return longitude;
	}

	public void setLongitude(float longitude) {
		this.longitude = longitude;
	}

	public float getLatitude() {
		return latitude;
	}

	public void setLatitude(float latitude) {
		this.latitude = latitude;
	}

	public Date getDate() {
		return date;
	}

	public void setDate(Date date) {
		this.date = date;
	}	
}