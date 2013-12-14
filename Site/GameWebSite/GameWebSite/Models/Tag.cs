using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class Tag
    {
        [Key]
        private string TagID { get; set; }
        private string TagOriginalID { get; set; }
        private string Palavra { get; set; }
    }
}