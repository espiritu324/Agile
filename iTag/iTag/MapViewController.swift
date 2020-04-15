//
//  MapViewController.swift
//  iTag
//
//  Created by apple on 4/11/20.
//  Copyright © 2020 apple. All rights reserved.
//

import UIKit
import MapKit
import CoreLocation

class MapViewController: UIViewController {

    @IBOutlet var mapView: UIView!
    @IBOutlet weak var Map: MKMapView!
    
    let locationManager = CLLocationManager()
    let regionInMeters: Double = 10000
    
    override func viewDidLoad() {
        super.viewDidLoad()
        
        checkLocationServices()
    }
    
    func setupLocationManager() {
        //locationManager.delegate = self as? CLLocationManagerDelegate
        locationManager.desiredAccuracy = kCLLocationAccuracyBest
    }
        
    func checkLocationServices() {
        if CLLocationManager.locationServicesEnabled() {
            setupLocationManager()
                checkLocationAuthorization()
        } else {
                
        }
    }
    
    func centerViewOnUserLocation() {
        if let location = locationManager.location?.coordinate {
            let region = MKCoordinateRegion.init(center: location, latitudinalMeters: regionInMeters, longitudinalMeters: regionInMeters)
            Map.setRegion(region, animated: true)
        }
    }
        
    func checkLocationAuthorization() {
        switch CLLocationManager.authorizationStatus() {
        case.authorizedWhenInUse:
            centerViewOnUserLocation()
            break
            
        case .notDetermined:
                //
            break
        case .restricted:
            break
        case .denied:
            break
        case .authorizedAlways:
            break
        @unknown default:
            break
        }
        
    }
    

    /*
    // MARK: - Navigation

    // In a storyboard-based application, you will often want to do a little preparation before navigation
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
        // Get the new view controller using segue.destination.
        // Pass the selected object to the new view controller.
    }
    */



//extension MapViewController: CLLocationManagerDelegate {
//
//    func locationManager( manager: CLLocationManager, didUpdateLocations locations: [CLLocation]) {
//
//    }
//
//    func locationManager(_ manager: CLLocationManager, didChangeAuthorization status: CLAuthorizationStatus) {
//        <#code#>
//    }
//
//}
}
