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
    var players=[PFUser]()
    override func viewDidLoad() {
        super.viewDidLoad()
        
        tableView.dataSource = self
        tableView.delegate = self

        // Do any additional setup after loading the view.
    }
    
    func tableView(_ tableView: UITableView, numberOfRowsInSection section: Int) -> Int {
//        let player = players[section]
//        let playerCount = (player["status"] as? [PFObject]) ?? []
//
//
//
//        return playerCount.count
        return 8
    }
//    func numberSections(in tableView: UITableView) -> Int {
//
//        return players.count
//
//    }
    let usernames = ["user1", "user2", "david", "admin", "zen", "latlongtest", "john", "test2"]
    func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
       
        let cell = tableView.dequeueReusableCell(withIdentifier: "PlayerCell") as! PlayerCell
//        let player = players[indexPath.row]
//        let player_ = player.username as! PFUser
        cell.playerLabel!.text = usernames[indexPath.row]
        if(indexPath.row==4){
            cell.statusLabel!.text = "Current Status: IT"
        }else{
        cell.statusLabel!.text = "Current Status: Hiding"
        }
        
        return cell
        
    }
    
    
    


}

