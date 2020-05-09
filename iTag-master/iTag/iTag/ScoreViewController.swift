//
//  ScoreViewController.swift
//  iTag
//
//  Created by David Espiritu on 5/9/20.
//  Copyright © 2020 apple. All rights reserved.
//

import UIKit
import Parse

class ScoreViewController: UIViewController, UITableViewDelegate, UITableViewDataSource {

    
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
            return 7
        }
    //    func numberSections(in tableView: UITableView) -> Int {
    //
    //        return players.count
    //
    //    }
        let usernames = ["user1", "user2", "david", "admin", "zen", "latlongtest", "john", "test2"]
        let score = ["500", "100", "200", "0", "1500", "1000", "800", "0"]
        let lat = ["33.715736", "33.715736", "33.715736", "33.715736", "33.715736", "33.715736", "33.715736", "33.715736"]
        let long = ["-111.161092", "-111.161092", "-111.161092", "-111.161092", "-111.161092", "-111.161092", "-111.161092", "-111.161092"]
        
        func tableView(_ tableView: UITableView, cellForRowAt indexPath: IndexPath) -> UITableViewCell {
           
            let cell = tableView.dequeueReusableCell(withIdentifier: "PlayerCell") as! scoreCell
    //        let player = players[indexPath.row]
    //        let player_ = player.username as! PFUser
            cell.usernameLabel!.text = usernames[indexPath.row]
            if(indexPath.row==4){
                cell.statusLabel!.text = "Current Status: IT"
            }else{
            cell.statusLabel!.text = "Current Status: Hiding"
            }
            cell.scoreLabel!.text = score[indexPath.row]
            cell.latLabel!.text = lat[indexPath.row]
            cell.longLabel!.text = long[indexPath.row]
            
            
            return cell
            
        }
        
        
        



}
