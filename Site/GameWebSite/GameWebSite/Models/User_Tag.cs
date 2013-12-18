using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class User_Tag
    {
        
        private int User_TagID { get; set; }
        private int UserID { get; set; }
        private int TagID { get; set; }
    }
}