package org.ishan.vms.model;

import java.util.Date;
import javax.xml.bind.annotation.*;

@XmlRootElement
public class Data {
	
	private long id;
	private float data;
	private Date date;
	
	public Data(){
		
	}
	
	public Data(int id, float data){
		this.id = id;
		this.data = data;
		this.date = new Date();
	}
	public long getId(){
		return id;
	}
	public void setId(long id){
		this.id = id;
	}
	
	public float getData() {
		return data;
	}
	public void setData(float data) {
		this.data = data;
	}
	public void setDate(Date date) {
		this.date = date;
	}
	public Date getDate() {
		return date;
	}
	
}
