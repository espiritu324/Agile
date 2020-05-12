//
//  PlayerCell.swift
//  iTag
//
//  Created by apple on 4/15/20.
//  Copyright © 2020 apple. All rights reserved.
//

import UIKit

class PlayerCell: UITableViewCell {
    
    
//    @IBOutlet weak var playerLabel: UILabel!
//
//    @IBOutlet weak var statusLabel: UILabel!
//
//    @IBOutlet weak var profileView: UIImageView!
    @IBOutlet weak var profileView: UIImageView!
    @IBOutlet weak var playerLabel: UILabel!
    @IBOutlet weak var statusLabel: UILabel!
    
    override func awakeFromNib() {
        super.awakeFromNib()
        // Initialization code
    }

    override func setSelected(_ selected: Bool, animated: Bool) {
        super.setSelected(selected, animated: animated)

        // Configure the view for the selected state
    }

}
