using System;
using System.Collections.Generic;
using System.Linq;
using System.Web;
using System.ComponentModel.DataAnnotations;

namespace GameWebSite.Models
{
    public class EstadoDeLigacao
    {
        [Key]
        private string EstadoDeLigacaoID { get; set; }
        private string Estado { get; set; }
    }
}