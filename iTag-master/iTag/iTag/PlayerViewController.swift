//
//  PlayerViewController.swift
//  iTag
//
//  Created by apple on 4/14/20.
//  Copyright © 2020 apple. All rights reserved.
//

import UIKit
import Parse

class PlayerViewController: UIViewController, UITableViewDataSource, UITableViewDelegate {
    
    
//    @IBOutlet weak var tableView: UITableView!
    
    @IBOutlet weak var tableView: UITableView!
    var players=[PFObject]()

    override func viewDidLoad() {
        super.viewDidLoad()
        
        tableView.dataSource = self
        tableView.delegate = self
    
        // Do any additional setup after loading the view.
    }
    
    override func viewDidAppear(_ animated: Bool) {
        super.viewDidAppear(animated)
        
        let query = PFQuery(className: "User")
        query.includeKey("objectId")
        query.limit = 20
        
        query.findObjectsInBackground { (players, error) in
            if self.players != nil {
                self.players = players!
                self.tableView.reloadData()
            }
        }
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
//        let player = players[section]
//        let playerCount = (player["status"] as? [PFObject]) ?? []
//
        return players.count
    }
//    func numberSections(in tableView: UITableView) -> Int {
//
//        return players.count
//
//    }
//    let usernames = ["user1", "user2", "david", "admin", "zen", "latlongtest", "john", "test2"]
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
       print("Error crap")
        let cell = tableView.dequeueReusableCell(withIdentifier: "PlayerCell") as! PlayerCell
        let player = players[indexPath.row]
//        cell.
        cell.playerLabel!.text = player["latitude"] as? String
        
        //        if(indexPath.row==4){
//            cell.statusLabel!.text = "Current Status: IT"
//        }else{
//        cell.statusLabel!.text = "Current Status: Hiding"
//        }
        
        return cell
        
    }
    
    override func prepare(for segue: UIStoryboardSegue, sender: Any?) {
           // Get the new view controller using segue.destination.
           // Pass the selected object to the new view controller.
           
           let cell = sender as! UITableViewCell
           let indexPath = tableView.indexPath(for: cell)!
           let player = players[indexPath.row]
           
           let PlayerViewController = segue.destination as! PlayerViewController
           PlayerViewController.player = player
           tableView.deselectRow(at: indexPath, animated: true)
       }
    


}

